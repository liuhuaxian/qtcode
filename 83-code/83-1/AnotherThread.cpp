#include "AnotherThread.h"
#include <QDebug>

AnotherThread::AnotherThread(QObject *parent) :
    QObject(parent)
{
    moveToThread(&m_thread); //将AnotherThread对象创建的对象的依附设置到m_thread上。

    //此时槽函数tmain()的执行将会在m_thread线程中执行。
    connect(&m_thread, SIGNAL(started()), this, SLOT(tmain()));
}

void AnotherThread::tmain()
{
    qDebug() << "void AnotherThread::tmain() tid = " << QThread::currentThreadId();

    for(int i=0; i<10; i++)
    {
        qDebug() << "void AnotherThread::tmain() i = " << i;
    }

    qDebug() << "void AnotherThread::tmain() end";

    m_thread.quit();//结束线程的事件循环。
}

void AnotherThread::start()
{
    m_thread.start();
}

void AnotherThread::terminate()
{
    m_thread.terminate();
}

void AnotherThread::exit(int c)
{
    m_thread.exit(c);
}

AnotherThread::~AnotherThread()
{
    m_thread.wait(); //同步的方式等待线程的运行结束，才回收对象的资源
}
