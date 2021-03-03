#include <QtCore/QCoreApplication>
#include <QThread>
#include <QDebug>
#include "MyThread.h"
#include "SyncThread.h"
#include "AsyncThread.h"

void test()
{
    MyThread t;

    t.start();
}

void sync_thread()
{
    SyncThread st;

    st.start();
}

void async_thread()
{
    AsyncThread* at = AsyncThread::NewInstance();

   // at->moveToThread(at); //此时线程将自己等待自己结束，按理论线程将不可能结束。

    at->start();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "main() tid = " << QThread::currentThread();

    // test(); //线程对象生命结束早于线程的执行，则会出现错误警告
    // sync_thread();  //线程对象以同步的方式等待线程执行结束，才释放空间
     async_thread();  //线程的结束以异步通知的方式通知线程对象。
    
    return a.exec();
}
