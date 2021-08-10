#include "QCalculator.h"

QCalculator::QCalculator()
{
}

bool QCalculator::construct()
{
    m_ui = QCalculatorUI::NewInstance();

    if( m_ui != NULL )
    {
        m_ui->setCalculator(&m_cal); //将负责UI的类和实际逻辑的类联系到一起。
    }

    return (m_ui != NULL);
}

QCalculator* QCalculator::NewInstance()
{
    QCalculator* ret = new QCalculator();

    if( (ret == NULL) || !ret->construct() )
    {
        delete ret;
        ret = NULL;
    }

    return ret;
}


void QCalculator::show()
{
    m_ui->show();
}

QCalculator::~QCalculator()
{
    delete m_ui;
}
