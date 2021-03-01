#include "Widget.h"
#include <QPainter>
#include <QPointF>
#include <QPen>
#include <qmath.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen;

    pen.setColor(Qt::red);      //设置画笔的颜色
    pen.setStyle(Qt::SolidLine); //设置画笔的画出的线的样式
    pen.setWidthF(0.01);        //设置画笔画出的线的宽度

    painter.setPen(pen);

    painter.setViewport(50, 50, width()-100, height()-100);
    //窗口的大小设定相当于定义视口中的坐标系的尺度。
    //视口中的(50，50)相当于窗口中的(-10,2),然后将width()-100分成20等分, height()-100分成4等分。
    painter.setWindow(-10, 2, 20, -4); // (-10, 2)    (10, -2)

    //填充的坐标系是根据窗口对应的坐标系来填充的。
    painter.fillRect(-10, 2, 20, -4, Qt::black);


    //以下x轴和y轴怎么没有绘制出来？？ 调整画笔的线宽可以将线显示出来。放大窗口大小也能正常显示
    painter.drawLine(QPointF(-10, 0), QPointF(10, 0));   // x
    painter.drawLine(QPointF(0, 2), QPointF(0, -2));     // y


    for(qreal x=-10; x<10; x+=0.01)
    {
        qreal y = qSin(x);

        painter.drawPoint(QPointF(x, y));
    }
}

Widget::~Widget()
{
    
}
