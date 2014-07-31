#include "Tray.h"
#include <QIcon>
Tray::Tray(QObject *parent) :
    QSystemTrayIcon(parent)
{
    QIcon icon(":/0.png");
    setIcon(icon);
}
