#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <QObject>
#include <QList>
#include "ScoreInfo.h"

class DataSource : public QObject
{
    Q_OBJECT

    QList<ScoreInfo> m_data;
    //解析line将解析的结果存放在info中
    bool parse(QString line, ScoreInfo& info);
public:
    explicit DataSource(QObject* parent = 0);

    //解析path路径指定文件的内容将其放入到m_data中
    bool setDataPath(QString path);

    QList<ScoreInfo> fetchData();
    int count();
};

#endif // DATASOURCE_H
