#include "TestThread.h"
#include <QDebug>

TestThread::TestThread(QObject *parent) :
    QThread(parent)
{
    connect(this, SIGNAL(testSignal()), this, SLOT(testSlot()));
}

void TestThread::run()
{
    qDebug() << "void TestThread::run() -- begin tid = " << currentThreadId();

    for(int i=0; i<5; i++)
    {
        qDebug() << "void TestThread::run() i = " << i;

        sleep(1);
    }

    emit testSignal();

    exec(); //线程开启事件循环

    qDebug() << "void TestThread::run() -- end"; //事件循环不结束此处将不会打印
}

void TestThread::testSlot()
{
    qDebug() << "void TestThread::testSlot() tid = " << currentThreadId();
}
