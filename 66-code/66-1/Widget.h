#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QPoint>
#include <QList>

class Widget : public QWidget
{
    Q_OBJECT

    enum
    {
        LINE,
        RECT,
        ELLIPSE
    };

    struct DrawParam
    {
        int type;         //绘制的图形
        Qt::PenStyle pen; //画笔样式
        QPoint begin;
        QPoint end;
    };
    
    QPushButton m_testBtn;
    QList<DrawParam> m_list;


protected slots:
    void onTestBtnClicked();
protected:
    void paintEvent(QPaintEvent *);
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
