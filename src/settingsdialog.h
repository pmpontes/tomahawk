/* === This file is part of Tomahawk Player - <http://tomahawk-player.org> ===
 *
 *   Copyright 2010-2011, Christian Muehlhaeuser <muesli@tomahawk-player.org>
 *   Copyright 2010-2011, Leo Franchi <lfranchi@kde.org>
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

#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QModelIndex>

#include "config.h"

class LoadingSpinner;
class QListWidgetItem;
class Ui_StackedSettingsDialog;
class SipPlugin;
class ResolversModel;
class QNetworkReply;

namespace Ui
{
    class SettingsDialog;
    class ProxyDialog;
}

namespace Tomahawk
{
    namespace Accounts
    {
        class AccountModel;
        class Account;
        class AccountFactory;
class Account;
}
}

class ProxyDialog : public QDialog
{
Q_OBJECT

public:
    explicit ProxyDialog( QWidget* parent = 0 );
    ~ProxyDialog() {};

    void saveSettings();

private slots:
    void proxyTypeChangedSlot( int index );

private:
    Ui::ProxyDialog* ui;
    QHash<int,int> m_forwardMap;
    QHash<int,int> m_backwardMap;
};

class SettingsDialog : public QDialog
{
Q_OBJECT

public:
    explicit SettingsDialog( QWidget* parent = 0 );
    ~SettingsDialog();

protected:
    void changeEvent( QEvent* e );

private slots:
    void onRejected();

    void toggleUpnp( bool preferStaticEnabled );
    void showProxySettings();

    void testLastFmLogin();
    void onLastFmFinished();

    void openAccountConfig( Tomahawk::Accounts::Account* );
    void createAccountFromFactory( Tomahawk::Accounts::AccountFactory* );
    void accountContextMenuRequest( const QPoint& );
    void accountDeleted( bool );
    void onAccountRowDeleted( bool );

    void accountsSelectionChanged();
    void getMoreResolvers();
    void getMoreResolversFinished( int );

    void accountInstalled( Tomahawk::Accounts::Account* account );
    void accountUninstalled( const QString& acct );

    void accountConfigClosed( int value );
    void accountCreateConfigClosed( int value );

    void updateScanOptionsView();

    void changePage( QListWidgetItem*, QListWidgetItem* );
    void serventReady();

    void requiresRestart();

private:
    void createIcons();
    void handleAccountAdded( Tomahawk::Accounts::Account* p, bool added );

    Ui_StackedSettingsDialog* ui;

    ProxyDialog m_proxySettings;
    bool m_rejected;
    Tomahawk::Accounts::AccountModel* m_accountModel;
    LoadingSpinner* m_sipSpinner;
};

#endif // SETTINGSDIALOG_H

struct A;
