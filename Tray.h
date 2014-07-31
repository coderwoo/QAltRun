#ifndef TRAY_H
#define TRAY_H

#include <QSystemTrayIcon>

class Tray : public QSystemTrayIcon
{
    Q_OBJECT
public:
    explicit Tray(QObject *parent = 0);

signals:

public slots:

};

#endif // TRAY_H
