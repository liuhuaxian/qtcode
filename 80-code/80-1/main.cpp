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

    QObject::connect(&t, SIGNAL(started()), &m, SLOT(getStarted()));
    QObject::connect(&t, SIGNAL(testSignal()), &m, SLOT(testSlot()));

    //将对象m和t的依附性都设置到t线程上，此时发送给对象m和t的信号均会在t线程的事件循环中处理
    m.moveToThread(&t);
    t.moveToThread(&t);

    t.start();

    t.wait(8 * 1000);

    t.quit();//结束t线程的事件循环

    return a.exec();
}
