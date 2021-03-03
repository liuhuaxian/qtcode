#include <QCoreApplication>
#include <QDebug>
#include "TextMessage.h"

class Test
{
public:
    Test();
    ~Test();
public:
    const double PI = 3.14;
    int b = (int)this->PI;    //不是不允许这么赋值么？
private:
    int a = 1;  //?
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TextMessage tm("AB", "1234567890");
    QString s = tm.serialize();

    qDebug() << s;

    TextMessage tmt;

    tmt.unserialize(s);

    qDebug() << tmt.type();
    qDebug() << tmt.length();
    qDebug() << tmt.data();

    return a.exec();
}
