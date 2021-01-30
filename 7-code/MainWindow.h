#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // MAINWINDOW_H
