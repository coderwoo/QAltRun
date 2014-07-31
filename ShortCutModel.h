#ifndef SHORTCUTMODEL_H
#define SHORTCUTMODEL_H

#include <QAbstractTableModel>
#include "ShortCut.h"

class ShortCutModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ShortCutModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

signals:

public slots:

};

#endif // SHORTCUTMODEL_H
