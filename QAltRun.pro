#-------------------------------------------------
#
# Project created by QtCreator 2014-07-24T10:52:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QAltRun
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        RunDlg.cpp \
    Tray.cpp \
    3rdparty/qxtglobal.cpp \
	3rdparty/qxtglobalshortcut.cpp \
    ShortCutModel.cpp \
    TableView.cpp \
    CmdLineEdit.cpp

mac {
	SOURCES += 3rdparty/qxtglobalshortcut_mac.cpp
}

win32 {
	SOURCES += 3rdparty/qxtglobalshortcut_win.cpp
}

unix {
	SOURCES += 3rdparty/qxtglobalshortcut_x11.cpp
}
HEADERS  += RunDlg.h \
    Tray.h \
    3rdparty/qxtglobal.h \
    3rdparty/qxtglobalshortcut.h \
    3rdparty/qxtglobalshortcut_p.h \
    ShortCutModel.h \
    TableView.h \
    CmdLineEdit.h

RESOURCES += \
    resources.qrc

