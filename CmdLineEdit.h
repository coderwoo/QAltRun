#ifndef CMDLINEEDIT_H
#define CMDLINEEDIT_H

#include <QLineEdit>

class CmdLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit CmdLineEdit(QWidget *parent = 0);

Q_SIGNALS:
    void commandSelect(int key);

public slots:
protected:
    void keyReleaseEvent(QKeyEvent *ev);
    void keyPressEvent(QKeyEvent *ev);

};

#endif // CMDLINEEDIT_H
