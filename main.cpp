#include "RunDlg.h"
#include <QApplication>
#include "Tray.h"
#include "3rdparty/qxtglobalshortcut.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Tray tray;
    tray.show();

    RunDlg w;
    w.show();

    QxtGlobalShortcut * shortcut = new QxtGlobalShortcut(QKeySequence("Alt+t"), &w);
    QObject::connect(shortcut, SIGNAL(activated()),&w, SLOT(show()));

    return a.exec();
}
