#include "MyLineEdit.h"
#include <QDebug>
#include <QEvent>
#include <QKeyEvent>

MyLineEdit::MyLineEdit(QWidget *parent) :
    QLineEdit(parent)
{
}

bool MyLineEdit::event(QEvent* e)
{
    if( e->type() == QEvent::KeyPress )
    {
        qDebug() << "MyLineEdit::event";
    }
    return QLineEdit::event(e);
}

void MyLineEdit::keyPressEvent(QKeyEvent* e)
{
    qDebug() << "MyLineEdit::keyPressEvent";

    QLineEdit::keyPressEvent(e);

    //清除accept参数表示事件接收器不想要该事件。不需要的事件可能会传播到父小部件
    e->accept();//此处不管时ignore还是accept怎样事件都会传递到父组件上。？？

    //

}
