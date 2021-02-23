#include "Widget.h"
#include "StringEvent.h"
#include <QMouseEvent>
#include <QDebug>
#include <QApplication>

Widget::Widget(QWidget *parent)
    : QWidget(parent), m_edit(this)
{
    m_edit.installEventFilter(this);
}

bool Widget::event(QEvent* evt)
{
    //当双击widget对象时产生的StringEvent对象。
    if( evt->type() == QMouseEvent::MouseButtonDblClick )
    {
        qDebug() << "event: Before sentEvent";

        StringEvent e("D.T.Software");

        //将自定义事件阻塞式的发送给m_edit组件
        QApplication::sendEvent(&m_edit, &e);

        qDebug() << "event: After sentEvent";
    }

    return QWidget::event(evt);
}

bool Widget::eventFilter(QObject* obj, QEvent* evt)
{
    //处理自定义的事件。由m_edit的事件过滤器进行处理。
    if( (obj == &m_edit) && (evt->type() == StringEvent::TYPE) )
    {
        StringEvent* se = dynamic_cast<StringEvent*>(evt);

        qDebug() << "Receive: " << se->data();

        m_edit.insert(se->data());

        return true; //返回true则该事件停止传递给父组件
    }

    return QWidget::eventFilter(obj, evt);
}

Widget::~Widget()
{
    
}
