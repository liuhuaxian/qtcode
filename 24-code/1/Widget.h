#ifndef _WIDGET_H_
#define _WIDGET_H_

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif
