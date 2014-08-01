#include "RunDlg.h"
#include <QLineEdit>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QDebug>
#include <QProcess>
#include <QTimer>
#include <QKeyEvent>
#include "CmdLineEdit.h"
#include "ShortCutModel.h"
#include "TableView.h"

RunDlg::RunDlg(QWidget *parent) :
    QDialog(parent)
{
    m_pLineEdit  = new CmdLineEdit(this);
    m_pTable     = new TableView(this);
    m_pModel     = new ShortCutModel();
    m_pModel->loadItems("a.txt");
    m_pTable->setModel(m_pModel);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(m_pLineEdit);
    layout->addWidget(m_pTable);
    setLayout(layout);

    m_pTimer = new QTimer(this);

    connect(m_pTimer, SIGNAL(timeout()),
            this, SLOT(hide()));

    connect(m_pLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(resetTimer()));

    connect(m_pLineEdit, SIGNAL(commandSelect(int)),
            m_pModel, SLOT(shortCutSelect(int)));

    connect(m_pLineEdit, SIGNAL(commandSelect(int)),
            this, SLOT(hide()));

    connect(m_pTable, SIGNAL(clicked(QModelIndex)),
            this, SLOT(resetTimer()));

    connect(m_pLineEdit, SIGNAL(textChanged(QString)),
            m_pModel, SLOT(updateCmd(QString)));

    m_pModel->updateCmd(QString());
}

void RunDlg::resetTimer()
{
    m_pTimer->stop();
    m_pTimer->start(5000);
}

void RunDlg::show()
{
    resetTimer();
    m_pLineEdit->setFocus();
    QDialog::show();
}

void RunDlg::keyPressEvent(QKeyEvent *ev)
{
    if (ev->key() & Qt::Key_Escape) {
        hide();
    } else
        QDialog::keyPressEvent(ev);
}
