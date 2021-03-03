#include "SyncThread.h"
#include <QDebug>

SyncThread::SyncThread(QObject *parent) :
    QThread(parent)
{
}

void SyncThread::run()
{
    qDebug() << "void SyncThread::run() tid = " << currentThreadId();

    for(int i=0; i<3; i++)
    {
        qDebug() << "void SyncThread::run() i = " << i;

        sleep(1);
    }

    qDebug() << "void SyncThread::run() end";
}

SyncThread::~SyncThread()
{
    wait(); //同步的方式主动的等待线程的执行完成

    qDebug() << "SyncThread::~SyncThread() destroy thread object";
}
