#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT
protected:
    void dragEnterEvent(QDragEnterEvent* e);
    void dropEvent(QDropEvent* e);
    bool event(QEvent* e);
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
