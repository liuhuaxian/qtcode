#include <QCoreApplication>
#include <QDebug>
#include "TextMessage.h"
#include "TxtMsgAssembler.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TextMessage tm("AB", "1234567890");
    QString s = tm.serialize();

    qDebug() << s;


    TxtMsgAssembler as;
    QSharedPointer<TextMessage> pt;

#if 0
    //模拟数据分两次到达。
    pt = as.assemble(s.toStdString().c_str(), s.length()-1);
    QString test('0');
    pt = as.assemble(test.toStdString().c_str(),1);
#endif

    pt = as.assemble(s.toStdString().c_str(), s.length());

    if( pt != NULL )
    {
        qDebug() << "assemble successfully";
        qDebug() << pt->type();
        qDebug() << pt->length();
        qDebug() << pt->data();
    }

    return a.exec();
}
