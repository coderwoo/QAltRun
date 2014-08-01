#include "Tray.h"

#include <QGuiApplication>

#include <QIcon>
#include <QMenu>
#include <QAction>

Tray::Tray(QObject *parent) :
    QSystemTrayIcon(parent)
{
    QIcon icon("icon\\trayIcon.png");
    this->setIcon(icon);
    this->setToolTip("AltRun");

    createContextMenu();

    connect ( this,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
              this,SLOT(activatedSlot(QSystemTrayIcon::ActivationReason)) );

    shortcut = new QxtGlobalShortcut(QKeySequence("Alt+t"), this);
    QObject::connect(shortcut, SIGNAL(activated()),this, SLOT(showDlgSlot()));
}

void Tray::createContextMenu ()
{
    menu = new QMenu();

    exitAction = new QAction( tr("退出"),this );
    showDlgAction = new QAction( tr("显示查找对话框"),this );

    connect( exitAction,SIGNAL(triggered()),this,SLOT(exitSlot()) );
    connect( showDlgAction,SIGNAL(triggered()),this,SLOT(showDlgSlot()) );

    menu->addAction(showDlgAction);
    menu->addAction(exitAction);

    setContextMenu(menu);
}

void Tray::activatedSlot(QSystemTrayIcon::ActivationReason reason)
{
    if( reason == QSystemTrayIcon::Trigger )
        emit (showDlgSignal () );
}

void Tray::exitSlot ()
{
    emit ( exitSignal() );
}
void Tray::showDlgSlot ()
{
    emit ( showDlgSignal () );
}
