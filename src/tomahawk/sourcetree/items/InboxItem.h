/* === This file is part of Tomahawk Player - <http://tomahawk-player.org> ===
 *
 *   Copyright 2013, Teo Mrnjavac <teo@kde.org>
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


#ifndef INBOXITEM_H
#define INBOXITEM_H

#include "SourceTreeItem.h"

class InboxItem : public SourceTreeItem
{
    Q_OBJECT
public:
    explicit InboxItem( SourcesModel* model, SourceTreeItem* parent );
    virtual ~InboxItem();

    virtual QString text() const;
    virtual QIcon icon() const;
    virtual int peerSortValue() const;
    void setSortValue( int value );

    int unlistenedCount() const;

public slots:
    virtual void activate();

private:
    int m_sortValue;
    QIcon m_icon;
    QString m_text;
};

#endif // INBOXITEM_H
