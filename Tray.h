#ifndef TRAY_H
#define TRAY_H

#include <QSystemTrayIcon>

#include <QAction>
#include <QMenu>

#include "3rdparty/qxtglobalshortcut.h"

class Tray : public QSystemTrayIcon
{
    Q_OBJECT
public:
    explicit Tray(QObject *parent = 0);

private:
    QxtGlobalShortcut* shortcut;
    QMenu * menu;

    QAction * exitAction;
    QAction * showDlgAction;

    void createContextMenu();
signals:
    // 当显示菜单
    void showDlgSignal();
    void exitSignal();
private slots:
    void exitSlot();
    void showDlgSlot();

    void activatedSlot(QSystemTrayIcon::ActivationReason);
};

#endif // TRAY_H
