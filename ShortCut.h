#ifndef SHORTCUTITEM_H
#define SHORTCUTITEM_H

#include <QString>
#include <QVector>
#include <QTextStream>
#include <QDebug>

struct ShortCutItem
{
    ShortCutItem(QString count = QString("F0"),
                 QString type = QString(),
                 QString shortCut = QString(),
                 QString name = QString(),
                 QString cmdLine = QString() );

    QString count;      // 通过altrun运行的次数
    QString type;       // 区分调用方式？
    QString shortCut;   // 快捷键
    QString name;       // 名称
    QString cmd;        // 命令

};

QTextStream& operator >> (QTextStream& in, ShortCutItem& item);
QTextStream& operator << (QTextStream& out, ShortCutItem& item);

QDebug& operator << (QDebug& out, ShortCutItem& item);

typedef ShortCutItem Item;
typedef Item *PItem;

class ShortCutVec
{
public:
    ShortCutVec();

    bool loadItems(QString filePath);
    bool saveItems(QString filePath);

    QVector<PItem>::iterator begin()    { return vec.begin();   }
    QVector<PItem>::iterator end()      { return vec.end();     }

private:
    QVector<PItem> vec;
};

#endif // SHORTCUTITEM_H
