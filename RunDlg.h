#ifndef RUNDLG_H
#define RUNDLG_H

#include <QDialog>

class CmdLineEdit;
class ShortCutModel;
class TableView;
class QTimer;

class RunDlg : public QDialog
{
    Q_OBJECT

public:
    explicit RunDlg(QWidget *parent = 0);

private:
    CmdLineEdit     *m_pLineEdit;
    TableView       *m_pTable;
    ShortCutModel   *m_pModel;
    QTimer          *m_pTimer;
    int              m_nCount;

public slots:
    void show();

protected slots:
    void resetTimer();

protected:
    void keyPressEvent(QKeyEvent *ev);
};

#endif // RUNDLG_H
