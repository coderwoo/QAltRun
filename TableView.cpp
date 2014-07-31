#include "TableView.h"
#include <QHeaderView>
TableView::TableView(QWidget *parent) :
    QTableView(parent)
{
    horizontalHeader()->hide();
    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    setMinimumHeight(300);
    setMinimumWidth(400);
}
