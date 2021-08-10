#ifndef TEXTMESSAGE_H
#define TEXTMESSAGE_H

#include <QObject>
#include <QByteArray>

class TextMessage : public QObject
{
    QString m_type;
    QString m_data;

public:
    TextMessage(QObject* parent = NULL);
    TextMessage(QString type, QString data, QObject* parent = NULL);

    QString type();
    int length();    //此时不代表字符串长度，而是字符串按照utf-8编码后所占的字节数。
    QString data();

    QByteArray serialize(); //关键计数字符串所占字节数。
    bool unserialize(QByteArray ba);
};

#endif // TEXTMESSAGE_H
