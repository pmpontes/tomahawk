/* === This file is part of Tomahawk Player - <http://tomahawk-player.org> ===
 *
 *   Copyright 2010-2015, Christian Muehlhaeuser <muesli@tomahawk-player.org>
 *   Copyright 2015,      Dominik Schmidt <domme@tomahawk-player.org>
 *
 *   Tomahawk is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Tomahawk is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Tomahawk. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Result.h"

#include "collection/Collection.h"
#include "database/Database.h"
#include "filemetadata/MetadataEditor.h"
#include "resolvers/ExternalResolverGui.h"
#include "resolvers/Resolver.h"
#include "utils/TomahawkUtilsGui.h"
#include "utils/Logger.h"

#include "Album.h"
#include "Pipeline.h"
#include "PlaylistInterface.h"
#include "Source.h"
#include "TomahawkSettings.h"
#include "Track.h"
#include "Typedefs.h"

using namespace Tomahawk;

static QHash< QString, result_wptr > s_results;
static QMutex s_mutex;

typedef QMap< QString, QPixmap > SourceIconCache;
Q_GLOBAL_STATIC( SourceIconCache, sourceIconCache );
static QMutex s_sourceIconMutex;

inline QString
sourceCacheKey( Resolver* resolver, const QSize& size, TomahawkUtils::ImageMode style )
{
    QString str;
    QTextStream stream( &str );
    stream << resolver << size.width() << size.height() << "_" << style;
    return str;
}


Tomahawk::result_ptr
Result::get( const QString& url, const track_ptr& track )
{
    if ( url.trimmed().isEmpty() || track.isNull() )
    {
        return result_ptr();
    }

    QMutexLocker lock( &s_mutex );
    if ( s_results.contains( url ) )
    {
        return s_results.value( url );
    }

    result_ptr r = result_ptr( new Result( url, track ), &Result::deleteLater );
    r->setWeakRef( r.toWeakRef() );
    s_results.insert( url, r );

    return r;
}


result_ptr
Result::getCached( const QString& url )
{
    if ( url.trimmed().isEmpty() )
    {
        return result_ptr();
    }

    QMutexLocker lock( &s_mutex );
    if ( s_results.contains( url ) )
    {
        return s_results.value( url );
    }

    return result_ptr();
}


Result::Result( const QString& url, const track_ptr& track )
    : QObject()
    , m_url( url )
    , m_isPreview( false )
    , m_checked( false )
    , m_bitrate( 0 )
    , m_size( 0 )
    , m_modtime( 0 )
    , m_fileId( 0 )
    , m_track( track )
{
    connect( Pipeline::instance(), SIGNAL( resolverRemoved( Tomahawk::Resolver* ) ), SLOT( onResolverRemoved( Tomahawk::Resolver* ) ), Qt::QueuedConnection );
}


Result::~Result()
{
    tDebug( LOGVERBOSE ) << Q_FUNC_INFO << toString();
}


void
Result::deleteLater()
{
    QMutexLocker lock( &s_mutex );

    if ( s_results.contains( m_url ) )
    {
        s_results.remove( m_url );
    }

    QObject::deleteLater();
}


void
Result::onResolverRemoved( Tomahawk::Resolver* resolver )
{
    if ( m_resolver.data() == resolver )
    {
        m_resolver = 0;
        emit statusChanged();
    }
}


collection_ptr
Result::resolvedByCollection() const
{
    return m_collection;
}


QString
Result::url() const
{
    return m_url;
}


bool
Result::checked() const
{
    return m_checked;
}


bool
Result::isPreview() const
{
    return m_isPreview;
}


QString
Result::mimetype() const
{
    return m_mimetype;
}


RID
Result::id() const
{
    if ( m_rid.isEmpty() )
        m_rid = uuid();

    return m_rid;
}


bool
Result::isOnline() const
{
    if ( !resolvedByCollection().isNull() )
    {
        return resolvedByCollection()->isOnline();
    }
    else
    {
        return !m_resolver.isNull();
    }
}


bool
Result::playable() const
{
    if ( resolvedByCollection() )
    {
        return resolvedByCollection()->isOnline();
    }

    return true;
}


QVariant
Result::toVariant() const
{
    QVariantMap m;
    m.insert( "artist", m_track->artist() );
    m.insert( "album", m_track->album() );
    m.insert( "track", m_track->track() );
    m.insert( "source", friendlySource() );
    m.insert( "mimetype", mimetype() );
    m.insert( "size", size() );
    m.insert( "bitrate", bitrate() );
    m.insert( "duration", m_track->duration() );
//    m.insert( "score", score() );
    m.insert( "sid", id() );
    m.insert( "discnumber", m_track->discnumber() );
    m.insert( "albumpos", m_track->albumpos() );
    m.insert( "preview", isPreview() );
    m.insert( "purchaseUrl", purchaseUrl() );

    if ( !m_track->composer().isEmpty() )
        m.insert( "composer", m_track->composer() );

    return m;
}


QString
Result::toString() const
{
    if ( m_track )
    {
        return QString( "Result(%1) %2 - %3%4 (%5)" )
                  .arg( id() )
                  .arg( m_track->artist() )
                  .arg( m_track->track() )
                  .arg( m_track->album().isEmpty() ? QString() : QString( " on %1" ).arg( m_track->album() ) )
                  .arg( m_url );
    }
    else
    {
        return QString( "Result(%1) (%2)" )
                  .arg( id() )
                  .arg( m_url );
    }
}


Tomahawk::query_ptr
Result::toQuery()
{
    if ( m_query.isNull() )
    {
        query_ptr query = Tomahawk::Query::get( m_track );
        if ( !query )
            return query_ptr();

        m_query = query->weakRef();

        QList<Tomahawk::result_ptr> rl;
        rl << weakRef().toStrongRef();
        query->addResults( rl );
        query->setResolveFinished( true );
        return query;
    }

    return m_query.toStrongRef();
}


void
Result::onOnline()
{
    emit statusChanged();
}


void
Result::onOffline()
{
    emit statusChanged();
}


void
Result::setResolvedByCollection( const Tomahawk::collection_ptr& collection , bool emitOnlineEvents )
{
    m_collection = collection;
    if ( emitOnlineEvents )
    {
        Q_ASSERT( !collection.isNull() );
        connect( collection.data(), SIGNAL( destroyed( QObject * ) ), SLOT( onOffline() ), Qt::QueuedConnection );
        connect( collection.data(), SIGNAL( online() ), SLOT( onOnline() ), Qt::QueuedConnection );
        connect( collection.data(), SIGNAL( offline() ), SLOT( onOffline() ), Qt::QueuedConnection );
    }
}


void
Result::setFriendlySource( const QString& s )
{
    m_friendlySource = s;
}


void
Result::setPreview( bool isPreview )
{
    m_isPreview = isPreview;
}


void
Result::setPurchaseUrl( const QString& u )
{
    m_purchaseUrl = u;
}


void
Result::setLinkUrl( const QString& u )
{
    m_linkUrl = u;
}


void
Result::setChecked( bool checked )
{
    m_checked = checked;
}


void
Result::setMimetype( const QString& mimetype )
{
    m_mimetype = mimetype;
}


void
Result::setBitrate( unsigned int bitrate )
{
    m_bitrate = bitrate;
}


void
Result::setSize( unsigned int size )
{
    m_size = size;
}


void
Result::setModificationTime( unsigned int modtime )
{
    m_modtime = modtime;
}


void
Result::setTrack( const track_ptr& track )
{
    m_track = track;
}


unsigned int
Result::fileId() const
{
    return m_fileId;
}


QString
Result::friendlySource() const
{
    if ( resolvedByCollection().isNull() )
    {
        return m_friendlySource;
    }
    else
        return resolvedByCollection()->prettyName();
}


QString
Result::purchaseUrl() const
{
    return m_purchaseUrl;
}


QString
Result::linkUrl() const
{
    return m_linkUrl;
}


QPixmap
Result::sourceIcon( TomahawkUtils::ImageMode style, const QSize& desiredSize ) const
{
    if ( resolvedByCollection().isNull() )
    {
        const ExternalResolver* resolver = qobject_cast< ExternalResolver* >( m_resolver.data() );
        if ( !resolver )
        {
            return QPixmap();
        }
        else
        {
            QMutexLocker l( &s_sourceIconMutex );

            const QString key = sourceCacheKey( m_resolver.data(), desiredSize, style );
            if ( !sourceIconCache()->contains( key ) )
            {
                QPixmap pixmap = resolver->icon( desiredSize );
                if ( pixmap.isNull() )
                    return pixmap;

                switch ( style )
                {
                    case TomahawkUtils::DropShadow:
                        pixmap = TomahawkUtils::addDropShadow( pixmap, QSize() );
                        break;

                    case TomahawkUtils::RoundedCorners:
                        pixmap = TomahawkUtils::createRoundedImage( pixmap, QSize() );
                        break;

                    default:
                        break;
                }

                sourceIconCache()->insert( key, pixmap );
                return pixmap;
            }
            else
            {
                return sourceIconCache()->value( key );
            }
        }
    }
    else
    {
        QPixmap avatar = resolvedByCollection()->icon( desiredSize );
        return avatar;
    }
}


unsigned int
Result::bitrate() const
{
    return m_bitrate;
}


unsigned int
Result::size() const
{
    return m_size;
}


unsigned int
Result::modificationTime() const
{
    return m_modtime;
}


void
Result::setFileId( unsigned int id )
{
    m_fileId = id;
}


Tomahawk::ResultProvider*
Result::resolvedBy() const
{
    if ( !m_collection.isNull() )
        return m_collection.data();

    return m_resolver.data();
}


void
Result::setResolvedByResolver( Tomahawk::Resolver* resolver )
{
    m_resolver = QPointer< Tomahawk::Resolver >( resolver );
}


QPointer< Resolver > Result::resolvedByResolver() const
{
    return m_resolver;
}


void
Result::doneEditing()
{
//    m_query.clear();
    emit updated();
}


track_ptr
Result::track() const
{
    return m_track;
}


void
Result::setDownloadFormats( const QList<DownloadFormat>& formats )
{
    m_formats.clear();
    foreach ( const DownloadFormat& format, formats )
    {
        if ( format.extension.toLower() == TomahawkSettings::instance()->downloadsPreferredFormat().toLower() )
        {
            m_formats.insert( 0, format );
        }
        else
        {
            m_formats << format;
        }
    }

    if ( !m_formats.isEmpty() )
    {
        connect( TomahawkSettings::instance(), SIGNAL( changed() ), this, SLOT( onSettingsChanged() ), Qt::UniqueConnection );
    }
    else
    {
        disconnect( TomahawkSettings::instance(), SIGNAL( changed() ), this, SLOT( onSettingsChanged() ) );
    }
}


void
Result::onSettingsChanged()
{
    if ( TomahawkSettings::instance()->downloadsPreferredFormat().toLower() != m_formats.first().extension.toLower() )
    {
        setDownloadFormats( downloadFormats() );
        emit updated();
    }
}


downloadjob_ptr
Result::toDownloadJob( const DownloadFormat& format )
{
    if ( !m_downloadJob )
    {
        m_downloadJob = downloadjob_ptr( new DownloadJob( weakRef().toStrongRef(), format ) );
        connect( m_downloadJob.data(), SIGNAL( progress( int ) ), SIGNAL( updated() ) );
    }

    return m_downloadJob;
}


QWeakPointer<Result>
Result::weakRef()
{
    return m_ownRef;
}


void
Result::setWeakRef( QWeakPointer<Result> weakRef )
{
    m_ownRef = weakRef;
}
