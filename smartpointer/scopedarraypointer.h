#ifndef SCOPEDARRAYPOINTER_H
#define SCOPEDARRAYPOINTER_H

#include <QDebug>
#include <QScopedArrayPointer>

template <typename T>
class ScopedArrayPointer : public QScopedArrayPointer<T>
{
public:
    ScopedArrayPointer() : QScopedArrayPointer<T>()
    {
        qDebug() << "in ScopedArrayPointer()" ;
    }
    ScopedArrayPointer(T* p=Q_NULLPTR) : QScopedArrayPointer<T>(p)
    {
        qDebug() << "in ScopedArrayPointer(T* p=Q_NULLPTR)" ;
    }
    ~ScopedArrayPointer()
    {
        qDebug() << "in ~ScopedArrayPointer()";
    }
};


#endif // SCOPEDARRAYPOINTER_H
