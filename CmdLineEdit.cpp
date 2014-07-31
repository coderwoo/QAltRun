#include "CmdLineEdit.h"
#include <QKeyEvent>
#include <QDebug>

CmdLineEdit::CmdLineEdit(QWidget *parent) :
    QLineEdit(parent)
{
}

void CmdLineEdit::keyReleaseEvent(QKeyEvent *ev)
{
    int key = ev->key();
    // ignore key 0~9
    if (key >= Qt::Key_0 && key <= Qt::Key_9) {

    } else {
        QLineEdit::keyReleaseEvent(ev);
    }
}

void CmdLineEdit::keyPressEvent(QKeyEvent *ev)
{
    int key = ev->key();
    if (key >= Qt::Key_0 && key <= Qt::Key_9) {
        emit commandSelect(key);
    } else {
        QLineEdit::keyPressEvent(ev);
    }
}
