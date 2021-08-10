#include "Widget.h"
#include <QDebug>
#include <QEvent>
#include <QKeyEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent), myLineEdit(this)
{
    myLineEdit.installEventFilter(this);//给子组件安装事件过滤器
}

bool Widget::event(QEvent* e)
{
    if( e->type() == QEvent::KeyPress )
    {
        qDebug() << "Widget::event";
    }

    return QWidget::event(e);
}

void Widget::keyPressEvent(QKeyEvent* e)
{
    qDebug() << "Widget::keyPressEvent";

    QWidget::keyPressEvent(e);
}


//若事件过滤器返回真，则停止传递该事件，如果事件处理器返回假，则继续传统该事件给其父组件中继续处理。
bool Widget::eventFilter(QObject* obj, QEvent* e)
{
    bool ret = true;

    if( (obj == &myLineEdit) && (e->type() == QEvent::KeyPress) )
    {
        qDebug() << e->type();
        qDebug() << "Widget::eventFilter";

        QKeyEvent* evt = dynamic_cast<QKeyEvent*>(e);

        switch(evt->key())
        {
        case Qt::Key_0:
        case Qt::Key_1:
        case Qt::Key_2:
        case Qt::Key_3:
        case Qt::Key_4:
        case Qt::Key_5:
        case Qt::Key_6:
        case Qt::Key_7:
        case Qt::Key_8:
        case Qt::Key_9:
        case Qt::Key_Backspace:
            ret = false; //以上按键才将这些事件传递给父组件，其它的组件全部忽略掉。
            break;
        default:
            break;
        }
    }
    else
    {
        ret = QWidget::eventFilter(obj, e);
    }
    return ret;
}

Widget::~Widget()
{
    
}
