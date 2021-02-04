#include "QMyPushButton.h"
#include <QMouseEvent>

QMyPushButton::QMyPushButton(QWidget* parent, QButtonListener* listener) : QPushButton(parent)
{
    m_listener = listener;
}

void QMyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if( m_listener != NULL )
    {
        m_listener(this, e);

        e->accept(); //表示e这个信号是想要的信号

        //emit clicked(); //发送clicked的信号

        setDown(false);//将按钮设置为抬起状态
    }
    else
    {
        QPushButton::mouseReleaseEvent(e);
    }
}

