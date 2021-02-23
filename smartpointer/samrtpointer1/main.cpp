#include "sharepointer.h"
#include "test.h"
#include <QWeakPointer>
#include "scopedpointer.h"
#include "scopedarraypointer.h"

int main()
{
    /***************QSharedPointer*********/
    test* t = new test;

    SharePointer<test> p(t);

    //QSharedPointer<test> p2(t); //这样p2和p有各自的引用计数且为t，释放内存时将重复释放内存。

    SharePointer<test> *p2 = new SharePointer<test>;

    p2 = &p; //p和p2的引用计数都为2.
    p.clear(); //此时p2和p的引用计数都为1，不释放t所指向的空间。
    p2->clear(); //此时才真正的析构掉t所指向的地址。
    qDebug() << p2->isNull(); //true


    /*************QScopedPointer***********/
    qDebug() << "";
    qDebug() << "QScopedPointer test begin";
    test* t1 = new test;
    ScopedPointer<test>* scopedptr = new ScopedPointer<test>(t1);
    delete scopedptr; //当释放QScopedPointer类型的指针时，其指针指向的空间也自动释放。

    /*************QScopedArrayPointer***********/
    qDebug() << "";
    qDebug() << "QScopedArrayPointer test begin";
    ScopedArrayPointer<test> * scopedArrayPtr = new ScopedArrayPointer<test>(new test[2]);
    //scopedArrayPtr = &t2;
    delete scopedArrayPtr; //释放该指针所占用的内存时，其指向的内存空间也将释放 。

    while (1) {

    }

    return 0;
}
