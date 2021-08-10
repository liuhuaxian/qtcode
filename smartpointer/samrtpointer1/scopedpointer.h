#ifndef SCOPEDPOINTER_H
#define SCOPEDPOINTER_H

#include <QScopedPointer>
#include <QDebug>
template <typename T>
class ScopedPointer : QScopedPointer<T>
{
public:
    ScopedPointer(T *p = Q_NULLPTR):QScopedPointer<T>(p){
        qDebug() << "in ScopedPointer(T *p = Q_NULLPTR)";
    }
    ~ScopedPointer(){
        qDebug() << "in ~ScopedPointer()";
    }

};

#endif // SCOPEDPOINTER_H
