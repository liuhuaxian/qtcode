#include <QApplication>
#include "QCalculatorUI.h"
#include "QCalculatorDec.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCalculatorUI* cal = QCalculatorUI::NewInstance();
    int ret = -1;

    if( cal != NULL )
    {
        cal->show();

        ret = a.exec();

        delete cal;
    }

    return ret;
/*
    QCalculatorDec c;

    c.expression(" (5 - 8) * (5 - 6) ");

    qDebug() << c.result();

    return 0;*/
}
