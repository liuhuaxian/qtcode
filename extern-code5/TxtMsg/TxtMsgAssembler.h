#ifndef TXTMSGASSEMBLER_H
#define TXTMSGASSEMBLER_H

#include <QObject>
#include <QQueue>
#include <QSharedPointer>
#include "TextMessage.h"

class TxtMsgAssembler : public QObject
{
    QQueue<char> m_queue;
    QString m_type;
    int m_length;       //关键
    QByteArray m_data;

    void clear();
    QByteArray fetch(int n); //关键点
    bool makeTypeAndLength();
    TextMessage* makeMessage(); //关键点，需要将m_data转换成QString,进行组装
public:
    TxtMsgAssembler(QObject* parent = NULL);
    void prepare(const char* data, int len);
    QSharedPointer<TextMessage> assemble(const char* data, int len);
    QSharedPointer<TextMessage> assemble();
    void reset();
};

#endif // TXTMSGASSEMBLER_H
