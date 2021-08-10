#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include "TestThread.h"
#include "MyObject.h"

void direct_connection()
{
    static TestThread t;
    static MyObject m;

    //由于连接方式为直接连接，虽然m对象依附于主线程，但槽函数在线程t中被执行。此时信号的发送相当于直接调用槽函数
    QObject::connect(&t, SIGNAL(testSignal()), &m, SLOT(testSlot()), Qt::DirectConnection);

    t.start();

    t.wait(5 * 1000);

    t.quit();
}

void queued_connection()
{
    static TestThread t;
    static MyObject m;

    //此时槽函数在m对象依附的主线程中执行。信号发送给m对象依附的主线程的事件处理来处理。
    QObject::connect(&t, SIGNAL(testSignal()), &m, SLOT(testSlot()), Qt::QueuedConnection);

    t.start();

    qDebug() << "in void queued_connection()";

    t.wait(5 * 1000);

    t.quit();
}

void blocking_queued_connection()
{
    static TestThread t;
    static MyObject m;

    //此时槽函数在m对象依附的主线程中执行。信号发送给m对象依附的主线程的事件循环来处理。且m依附的线程还会阻塞等待信号处理完成。
    QObject::connect(&t, SIGNAL(testSignal()), &m, SLOT(testSlot()), Qt::BlockingQueuedConnection);

    t.start();

    qDebug() << "in void blocking_queued_connection()";

    t.wait(5 * 1000);

    t.quit();
}

void auto_connection()
{
    static TestThread t;
    static MyObject m;

    //此时相当于Qt::QueuedConnection
    QObject::connect(&t, SIGNAL(testSignal()), &m, SLOT(testSlot()));

    t.start();

    qDebug() << "in void auto_connection()";
    t.wait(5 * 1000);

    t.quit();
}

void unique_connection()
{
    static TestThread t;
    static MyObject m;

    //此时槽函数只会在m对象依附的主线程中执行一次
    QObject::connect(&t, SIGNAL(testSignal()), &m, SLOT(testSlot()), Qt::UniqueConnection);
    QObject::connect(&t, SIGNAL(testSignal()), &m, SLOT(testSlot()), Qt::UniqueConnection);

    t.start();

    t.wait(5 * 1000);

    t.quit();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "main() tid = " << QThread::currentThreadId();

    // direct_connection();
    // queued_connection();
    // blocking_queued_connection();
    // auto_connection();
     unique_connection();

    return a.exec();
}
