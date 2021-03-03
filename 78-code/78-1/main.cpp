#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QThread>
#include "TestThread.h"
#include "MyObject.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "main() tid = " << QThread::currentThreadId();

    TestThread t; //
    MyObject m;
    //m和t依附于主线程，且主线程开启了事件循环exec()，所以所有的信号都发送个主线程，由主线程的事件循环进行调度。
    //所以以下的槽函数均是在主线程中调用的，及其t线程中的槽函数也会在主线程中执行。

    QObject::connect(&t, SIGNAL(started()), &m, SLOT(getStarted()));
    QObject::connect(&t, SIGNAL(finished()), &m, SLOT(getFinished()));
    QObject::connect(&t, SIGNAL(terminated()), &m, SLOT(getTerminated()));

    t.start();
    
    return a.exec();
}
