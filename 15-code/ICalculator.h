#ifndef _ICALCULATOR_H_
#define _ICALCULATOR_H_

#include <QString>

//接口类
class ICalculator
{
public:
    virtual bool expression(const QString& exp) = 0;
    virtual QString result() = 0;
};

#endif
