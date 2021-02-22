#ifndef SCOPEDARRAYPOINTER_H
#define SCOPEDARRAYPOINTER_H

#include <QDebug>
#include <QScopedArrayPointer>

template <typename T>
class ScopedArrayPointer : public QScopedArrayPointer<T>
{
    ScopedArrayPointer() : QScopedArrayPointer<T>()
    {
        qDebug() << "in ScopedArrayPointer()" ;
    }
    ~ScopedArrayPointer()
    {
        qDebug() << "in ~ScopedArrayPointer()";
    }
};


#endif // SCOPEDARRAYPOINTER_H
