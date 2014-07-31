#include "ShortCutModel.h"

ShortCutModel::ShortCutModel(QObject *parent) :
    QAbstractTableModel(parent)
{
}

int ShortCutModel::rowCount(const QModelIndex &parent) const
{
    // always show 10 rows
    return 10;
}

int ShortCutModel::columnCount(const QModelIndex &parent) const
{
    // two columns: shortcut and name
    return 2;
}

QVariant ShortCutModel::data(const QModelIndex &index, int role) const
{
    // TODO
    return QVariant();
}
