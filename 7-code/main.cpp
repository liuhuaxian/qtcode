#include <QApplication>
#include <QPushButton>
#include <QDebug>

#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    QPushButton b(&w);   // 生成 QPushButton对象， 其父组件为 QWidget
    QPushButton b1(&w);


    b.setText("Button"); // 设置显示的字符串
    b.move(10, 10);      // 移动到坐标 (10, 10)
    b.resize(100, 50);   // 设置大小 width = 100, height = 25

    b1.setText("Button"); // 设置显示的字符串
    b1.move(120, 10);      // 移动到坐标 (120, 10)
    b1.resize(100, 50);   // 设置大小 width = 100, height = 25


    //w.resize(220, 100);
    w.move(120, 120);
    w.show();

    qDebug()<<"QWidget:";
    qDebug()<<w.x();
    qDebug()<<w.y();
    qDebug()<<w.width();
    qDebug()<<w.height();

    qDebug()<<"QWidget::geometry()";
    qDebug()<<w.geometry().x();
    qDebug()<<w.geometry().y();
    qDebug()<<w.geometry().width();
    qDebug()<<w.geometry().height();

    qDebug()<<"QWidget::frameGeometry()";
    qDebug()<<w.frameGeometry().x();
    qDebug()<<w.frameGeometry().y();
    qDebug()<<w.frameGeometry().width();
    qDebug()<<w.frameGeometry().height();
    
    return a.exec();
}
