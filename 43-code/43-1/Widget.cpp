#include "Widget.h"
#include <QMouseEvent>
#include <QApplication>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_pushButton.setParent(this);
    m_pushButton.setText("Test");

    connect(&m_pushButton, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
}

void Widget::onButtonClicked()
{
    // testSendEvent();
    testPostEvent();
}

void Widget::testSendEvent()
{
    //阻塞式事件发送，一般在栈上分配空间，需要自行进行释放空间
    QMouseEvent dbcEvt(QEvent::MouseButtonDblClick, QPoint(0, 0), Qt::LeftButton, Qt::NoButton, Qt::NoModifier);

    qDebug() << "Before sendEvent()";

    QApplication::sendEvent(this, &dbcEvt);

    qDebug() << "After sendEvent()";
}

void Widget::testPostEvent()
{
    //非阻塞式事件发送，必须在堆上产生事件对象，并且有事件处理后自动释放内存。
    QMouseEvent* dbcEvt = new QMouseEvent(QEvent::MouseButtonDblClick, QPoint(0, 0), Qt::LeftButton, Qt::NoButton, Qt::NoModifier);

    qDebug() << "Before postEvent()";

    QApplication::postEvent(this, dbcEvt);

    qDebug() << "After postEvent()";
}

bool Widget::event(QEvent* evt)
{
    if( evt->type() == QEvent::MouseButtonDblClick )
    {
        qDebug() << "event(): " << evt;
    }

    return QWidget::event(evt);
}

Widget::~Widget()
{
    
}
