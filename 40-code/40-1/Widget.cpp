#include "Widget.h"
#include <QDragEnterEvent>
#include <QMimeData>
#include <QDropEvent>
#include <QDebug>
#include <QList>
#include <QUrl>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    setAcceptDrops(true);//使能拖拽事件
}
bool Widget::event(QEvent* e)
{
    //qDebug() << "in event";
    //qDebug() << e->type();
    QWidget::event(e); //
}

//event(e) --> dragEnterEvent --> dropEvent
//当拖放操作进入组件时，该事件将被发送到组件
void Widget::dragEnterEvent(QDragEnterEvent* e)
{
    if( e->mimeData()->hasUrls() )
    {
        e->acceptProposedAction();
    }
    else
    {
        e->ignore();
    }
}

//QDropEvent类提供在拖放操作完成时发送的事件
void Widget::dropEvent(QDropEvent* e)
{
    if( e->mimeData()->hasUrls() )
    {
        QList<QUrl> list = e->mimeData()->urls();

        for(int i=0; i<list.count(); i++)
        {
            qDebug() << list[i].toLocalFile();//将URL转换成本地路径名
        }
    }
    else
    {
        e->ignore();
    }
}

Widget::~Widget()
{
    
}
