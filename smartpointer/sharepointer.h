#ifndef SHAREPOINTER_H
#define SHAREPOINTER_H
#include <QSharedPointer>
#include <QDebug>
template<typename X>
class SharePointer : public QSharedPointer<X>
{
public:
    SharePointer() : QSharedPointer<X>()
    {
        qDebug() << "in SharePointer";

    }

    SharePointer(X *ptr) : QSharedPointer<X>(ptr)
    {
        qDebug() << "In SharePointer(X *ptr)";
    }

    ~SharePointer(){
        qDebug() << " ~SharePointer()";
    }
};

#endif // SHAREPOINTER_H
