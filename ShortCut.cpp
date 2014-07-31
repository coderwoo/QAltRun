#include "ShortCut.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QDebug>

ShortCutItem::ShortCutItem(QString ct, QString ty, QString sc, QString na, QString cl)
    : count(ct), type(ty), shortCut(sc), name(na),  cmd(cl)
{
}

ShortCutVec::ShortCutVec()
{

}

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

QDebug& operator << (QDebug& out, ShortCutItem& item)
{
    out.nospace() << item.count << "\t"
                  << item.type << "\t"
                  << item.shortCut << "\t"
                  << item.name  << "\t"
                  << item.cmd;
    return out.space();
}

bool ShortCutVec::loadItems(QString filePath)
{
    QFile file(filePath);
    if (!file.open(QFile::ReadOnly))
        return false;
    QTextStream in(&file);
    while (!in.atEnd()) {

        QStringList list = in.readLine().split("|");
        //qDebug() << list;
        if (list.size() < 5)
            continue;
        PItem pItem = new Item(list[0].trimmed(), list[1].trimmed(),
                list[2].trimmed(), list[3].trimmed(), list[4].trimmed());
        vec.push_back(pItem);
    }
    return true;
}

bool ShortCutVec::saveItems(QString filePath)
{
    QFile file(filePath);
    if ( !file.open(QFile::WriteOnly))
        return false;
    QTextStream out(&file);
    for (auto it = vec.begin(); it!=vec.end(); it++)
        out << *(*it);
    return true;
}
