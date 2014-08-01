#ifndef TRAY_H
#define TRAY_H

#include <QSystemTrayIcon>

#include <QAction>
#include <QMenu>

class Tray : public QSystemTrayIcon
{
    Q_OBJECT
public:
    explicit Tray(QObject *parent = 0);

private:
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
