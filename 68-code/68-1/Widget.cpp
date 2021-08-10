#include "Widget.h"
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QBrush>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_group.setParent(this);
    m_group.setTitle("Setting");
    m_group.resize(600, 65);
    m_group.move(20, 20);

    m_freeBtn.setParent(&m_group);
    m_freeBtn.setText("Free");
    m_freeBtn.resize(70, 30);
    m_freeBtn.move(35, 20);
    m_freeBtn.setChecked(true);

    m_lineBtn.setParent(&m_group);
    m_lineBtn.setText("Line");
    m_lineBtn.resize(70, 30);
    m_lineBtn.move(140, 20);

    m_rectBtn.setParent(&m_group);
    m_rectBtn.setText("Rect");
    m_rectBtn.resize(70, 30);
    m_rectBtn.move(245, 20);

    m_ellipseBtn.setParent(&m_group);
    m_ellipseBtn.setText("Ellipse");
    m_ellipseBtn.resize(70, 30);
    m_ellipseBtn.move(350, 20);

    m_colorBox.setParent(&m_group);
    m_colorBox.resize(80, 25);
    m_colorBox.move(480, 23);
    m_colorBox.addItem("Black");
    m_colorBox.addItem("Blue");
    m_colorBox.addItem("Green");
    m_colorBox.addItem("Red");
    m_colorBox.addItem("Yellow");

    setFixedSize(width(), 600);

    m_current.type = NONE;
    m_current.color = Qt::white;
    m_current.points.clear();
}

Widget::DrawType Widget::drawType()
{
    DrawType ret = NONE;

    if( m_freeBtn.isChecked() )    ret = FREE;
    if( m_lineBtn.isChecked() )    ret = LINE;
    if( m_rectBtn.isChecked() )    ret = RECT;
    if( m_ellipseBtn.isChecked() ) ret = ELLIPSE;

    return ret;
}

Qt::GlobalColor Widget::drawColor()
{
    Qt::GlobalColor ret = Qt::black;

    if( m_colorBox.currentText() == "Black")    ret = Qt::black;
    if( m_colorBox.currentText() == "Blue")     ret = Qt::blue;
    if( m_colorBox.currentText() == "Green")    ret = Qt::green;
    if( m_colorBox.currentText() == "Red")      ret = Qt::red;
    if( m_colorBox.currentText() == "Yellow")   ret = Qt::yellow;

    return ret;
}

void Widget::mousePressEvent(QMouseEvent *evt)
{
    m_current.type = drawType();                //获取设置的类型
    m_current.color = drawColor();              //获取设置的颜色
    m_current.points.append(evt->pos());        //记录鼠标的起点值
}

void Widget::mouseMoveEvent(QMouseEvent *evt)
{
    append(evt->pos());

    update(); //更新widget的组件
}

void Widget::mouseReleaseEvent(QMouseEvent *evt)
{
    append(evt->pos());

    //保存当前绘画出来的图形的参数信息，避免在画下一条线的时候上一次绘画的图形消失。
    m_drawList.append(m_current);

    //重置m_current参数
    m_current.type = NONE;
    m_current.color = Qt::white;
    m_current.points.clear();

    update();
}

void Widget::append(QPoint p)
{
    //除了自由绘画外， m_current.points链表中的点的个数只有两个。
    if( m_current.type != NONE )
    {
        if( m_current.type == FREE )
        {
            m_current.points.append(p);
        }
        else
        {
            if( m_current.points.count() == 2 )
            {
                m_current.points.removeLast(); //移除链表中的第二个点
            }

            m_current.points.append(p);//将一个点添加到链表中。
        }
    }
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    for(int i=0; i<m_drawList.count(); i++)
    {
        draw(painter, m_drawList[i]); //绘制之前绘制过的图形
    }

    //实时的绘制图形。
    draw(painter, m_current);
}

void Widget::draw(QPainter& painter, DrawParam& param)
{
    if( (param.type != NONE) && (param.points.count() >= 2) )
    {
        int x = (param.points[0].x() < param.points[1].x()) ? param.points[0].x() : param.points[1].x();
        int y = (param.points[0].y() < param.points[1].y()) ? param.points[0].y() : param.points[1].y();
        int w = qAbs(param.points[0].x() - param.points[1].x()) + 1;
        int h = qAbs(param.points[0].y() - param.points[1].y()) + 1;

        painter.setPen(QPen(param.color));
        painter.setBrush(QBrush(param.color));

        switch(param.type)
        {
        case FREE:
            for(int i=0; i<param.points.count()-1; i++)
            {
                painter.drawLine(param.points[i], param.points[i+1]);
            }
            break;
        case LINE:
            painter.drawLine(param.points[0], param.points[1]);
            break;
        case RECT:
            painter.drawRect(x, y, w, h);
            break;
        case ELLIPSE:
            painter.drawEllipse(x, y, w, h);
            break;
        default:
            break;
        }
    }
}

Widget::~Widget()
{
    
}
