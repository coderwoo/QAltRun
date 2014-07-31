#include "RunDlg.h"
#include <QLineEdit>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QDebug>
#include <QProcess>
#include <QTimer>
#include "CmdLineEdit.h"
#include "ShortCutModel.h"
#include "TableView.h"

RunDlg::RunDlg(QWidget *parent) :
    QDialog(parent)
{
    m_pLineEdit  = new CmdLineEdit(this);
    m_pTable     = new TableView(this);
    m_pModel     = new ShortCutModel();

    m_pTable->setModel(m_pModel);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(m_pLineEdit);
    layout->addWidget(m_pTable);
    setLayout(layout);

    m_pTimer = new QTimer(this);

    connect(m_pTimer, SIGNAL(timeout()),
            this, SLOT(hide()));

    connect(m_pLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(commandUpdate(QString)));

    connect(m_pLineEdit, SIGNAL(commandSelect(int)),
            this, SLOT(commandSelect(int)));

    commandUpdate(QString());
}

void RunDlg::resetTimer()
{
    m_pTimer->stop();
    m_pTimer->start(5000);
}

void RunDlg::show()
{
    resetTimer();
    QDialog::show();
}

void RunDlg::commandUpdate(QString str)
{
//    resetTimer();
//    tableWidget->clear();
//    count = 0;
//    for (auto it = shortCuts->begin(); it!=shortCuts->end(); it++) {
//        PItem pItem = *it;
//        if (pItem->shortCut.startsWith(str, Qt::CaseInsensitive) ) {
//            QTableWidgetItem* tItem;
//            tItem = new QTableWidgetItem(pItem->shortCut);
//            tableWidget->setItem(count, 0, tItem);
//            tItem = new QTableWidgetItem(pItem->name);
//            tableWidget->setItem(count, 1, tItem);
//            tItem = new QTableWidgetItem(pItem->cmdLine);
//            tableWidget->setItem(count, 2, tItem);
//            count++;
//        }
//    }
}
void RunDlg::commandSelect(int key)
{
//    if (key == Qt::Key_0)
//        key += 10;
//    key -= Qt::Key_1;
//    if (key >= count)
//        return;
//    QString str = tableWidget->item(key, 2)->text();
//    qDebug() << key << str;
//    QProcess::execute(str);
}
