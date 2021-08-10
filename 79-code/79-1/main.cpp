#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QThread>
#include "TestThread.h"
#include "MyObject.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "main() tid = " << QThread::currentThreadId();

    TestThread t;
    MyObject m;

    //以下的槽函数均会在t线程中被调用。
    QObject::connect(&t, SIGNAL(started()), &m, SLOT(getStarted()));
    QObject::connect(&t, SIGNAL(testSignal()), &m, SLOT(testSlot()));

    m.moveToThread(&t); //将m对象依附在t线程上，此时发送给m对象的信号均会在t线程的事件循环中处理
    t.moveToThread(&t); //将t对象依附在t线程上

    t.start(); //开启t线程

    return a.exec();
}
