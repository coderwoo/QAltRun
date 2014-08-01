/*!
 * \file
 * \brief
 *
 * \author
 * \version
 * \date
 */
#ifndef SHORTCUTMODEL_H
#define SHORTCUTMODEL_H

#include <QAbstractTableModel>
#include <QTextStream>
#include <QDebug>
#include <QVector>
/*!
 * \brief The ShortCutItem struct
 */
struct ShortCutItem
{
    ShortCutItem(QString c = QString(),
                 QString t = QString(),
                 QString s = QString(),
                 QString n = QString(),
                 QString cm= QString()) :
        count(c), type(t), shortCut(s), name(n), cmd(cm) {}
    QString count;      // 通过altrun运行的次数
    QString type;       // 区分调用方式？
    QString shortCut;   // 快捷键
    QString name;       // 名称
    QString cmd;        // 命令
};

QTextStream& operator >> (QTextStream& in, ShortCutItem& item);
QTextStream& operator << (QTextStream& out, ShortCutItem& item);

typedef ShortCutItem Item;
typedef Item *PItem;
/*!
 * \brief The ShortCutModel class
 *
 */
class ShortCutModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ShortCutModel(QObject *parent = 0);

    // Returns the number of rows under the given parent.
    int rowCount(const QModelIndex &parent) const;

    // Returns the number of columns for the children
    // of the given parent.
    int columnCount(const QModelIndex &parent) const;

    // Returns the data stored under the given role
    // for the item referred to by the index.
    QVariant data(const QModelIndex &index, int role) const;

    // Sets the role data for the item at index to value.
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    // Returns the data for the given role and section in the header
    // with the specified orientation.
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role) const;

    // Load AltRun shorcut items from file
    bool loadItems(const QString& filePath);

    // Save AltRun shortcut items to file
    bool saveItems(const QString& filePath);

signals:

public slots:
    //
    void updateCmd(const QString& cmd);
    //
    void shortCutSelect(int key);

protected:
    QVector<ShortCutItem*>  m_pItems;       ///< 所有的AltRun启动项
    QVector<ShortCutItem*>  m_pTenItems;    ///< 最匹配的十条结果
    bool                    m_bUpdateTen;   ///< 判断是否更新m_pTenItems
    QString                 m_strCurCmd;    ///< 当前要查找的命令

    void updateTen();
};

#endif // SHORTCUTMODEL_H
