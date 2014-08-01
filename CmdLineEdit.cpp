#include "CmdLineEdit.h"
#include <QKeyEvent>
#include <QDebug>

CmdLineEdit::CmdLineEdit(QWidget *parent) :
    QLineEdit(parent)
{
    setFocusPolicy(Qt::ClickFocus);
}

void CmdLineEdit::keyReleaseEvent(QKeyEvent *ev)
{
    int key = ev->key();
    // ignore key 0~9
    if (key >= Qt::Key_0 && key <= Qt::Key_9) {

    } else if (key = Qt::Key_Escape) {
        //
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

void CmdLineEdit::focusInEvent(QFocusEvent *ev)
{
    emit focusIn();
    QLineEdit::focusInEvent(ev);
}
