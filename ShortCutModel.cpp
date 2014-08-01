#include "ShortCutModel.h"
#include <QFile>
#include <QStringList>
#include <QVariant>
#include <QProcess>
/*!
 * \brief 对'>>'操作符的重载，可以从流中读取ShortCutItem
 * \param in 要进行读取的流
 * \param item
 * \return
 */
QTextStream& operator >> (QTextStream& in, ShortCutItem& item)
{
    QString str = in.readLine();
    QStringList list = str.split("|");
    //qDebug() << list;
    if (list.size() < 4)
        return in;
    item.count = list[0].trimmed();
    item.shortCut = list[1].trimmed();
    item.name = list[2].trimmed();
    item.type = list[3].trimmed();
    item.cmd = list[4].trimmed();
    return in;
}

/*!
 * \brief 对'<<'操作符的重载，可以向流中写入ShortCutItem
 * \param out
 * \param item
 * \return
 */
QTextStream& operator << (QTextStream& out, ShortCutItem& item)
{
    QStringList list;
    list.append(item.count);
    list.append(item.type);
    list.append(item.shortCut);
    list.append(item.name);
    list.append(item.cmd);
    out << list.join("|");
    return out;
}

/*!
 * \brief 对'<<'操作符的重载，可以通过qDebug()输出ShortCutItem
 * \param out
 * \param item
 * \return
 */
QDebug& operator << (QDebug& out, ShortCutItem& item)
{
    out.nospace() << item.count << "\t"
                  << item.type << "\t"
                  << item.shortCut << "\t"
                  << item.name  << "\t"
                  << item.cmd;
    return out.space();
}

/*!
 * \brief ShortCutModel的构造函数
 * \param parent
 */
ShortCutModel::ShortCutModel(QObject *parent) :
    QAbstractTableModel(parent), m_bUpdateTen(true)
{
}

/*!
 * \brief 返回ShortCutModel的行数
 * \param parent
 * \return
 */
int ShortCutModel::rowCount(const QModelIndex &parent) const
{
    // always show 10 rows
    Q_UNUSED(parent);
    return 10;
}

/*!
 * \brief 返回ShortCutModel的列数
 * \param parent
 * \return
 */
int ShortCutModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    // two columns: shortcut and name
    return 2;
}

/*!
 * \brief 返回index位置的数据
 * \param index
 * \param role
 * \return
 */
QVariant ShortCutModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::TextAlignmentRole)
        return int(Qt::AlignHCenter|Qt::AlignVCenter);
    else if (role == Qt::DisplayRole) {
        if (index.row() >= m_pTenItems.size())
            return QVariant();
        switch (index.column()) {
        case 0:
            return m_pTenItems[index.row()]->shortCut;
        case 1:
            return m_pTenItems[index.row()]->name;
        }
    }
    return QVariant();
}

/*!
 * \brief 更新当前要查找的cmd
 * \param cmd
 */
void ShortCutModel::updateCmd(const QString &cmd)
{
    m_bUpdateTen = true;
    m_strCurCmd = cmd;
    updateTen();
}

/*!
 * \brief 从路径为filepath的文件中加载AltRun快捷项数据
 * \param filePath
 * \return
 */
bool ShortCutModel::loadItems(const QString& filePath)
{
    QFile file(filePath);
    if (!file.open(QFile::ReadOnly))
        return false;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QStringList list = in.readLine().split("|");
        if (list.size() < 5)
            continue;
        PItem pItem = new Item(list[0].trimmed(), list[1].trimmed(),
                list[2].trimmed(), list[3].trimmed(), list[4].trimmed());
        m_pItems.push_back(pItem);
    }
    return true;
}

/*!
 * \brief 将AltRun快捷项保存到路径为filePath的文件中
 * \param filePath
 * \return
 */
bool ShortCutModel::saveItems(const QString& filePath)
{
    QFile file(filePath);
    if ( !file.open(QFile::WriteOnly))
        return false;
    QTextStream out(&file);
    for (auto it = m_pItems.begin(); it!=m_pItems.end(); it++)
        out << *(*it);
    return true;
}

/*!
 * \brief 更新显示在TableView中的十项快捷项
 */
void ShortCutModel::updateTen()
{
    m_pTenItems.clear();
    for(auto it=m_pItems.begin(); it!=m_pItems.end(); it++) {
        PItem pItem = *it;
        if (pItem->shortCut.startsWith(m_strCurCmd, Qt::CaseInsensitive) ) {
            m_pTenItems.append(pItem);
            if (m_pTenItems.size() >= 10)
                break;
        }
    }
    m_bUpdateTen = false;
    emit dataChanged(QModelIndex(), QModelIndex());
}

/*!
 * \brief ShortCutModel::setData
 * \param index
 * \param value
 * \param role
 * \return
 */
bool ShortCutModel::setData(const QModelIndex &index,
                            const QVariant &value, int role)
{
    //if (index.isValid())
    return false;
}

/*!
 * \brief Returns the data for the given role and section in the header
 *        with the specified orientation.
 * \param section
 * \param orientation
 * \param role
 * \return
 */
QVariant ShortCutModel::headerData(int section, Qt::Orientation orientation,
                                   int role) const
{
    if(role != Qt::DisplayRole)
        return QVariant();
    if(orientation == Qt::Horizontal)
        return QVariant();
    else
        return QString::number((section+1)%10);
}

/*!
 * \brief 根据key的值启动相应的程序
 * \param idx Qt::Key_0 ~ Qt::Key_9
 */
void ShortCutModel::shortCutSelect(int key)
{
     if (key == Qt::Key_0)
        key += 10;
     key -= Qt::Key_1;
     if (key >= m_pTenItems.size())
        return;
     QString str = m_pTenItems[key]->cmd;
     qDebug() << str << QProcess::startDetached(str);
}
