#include <QtGui>
#include <QApplication>
#include <QLabel>
#include "Widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QWidget w(NULL, Qt::Window|Qt::WindowStaysOnTopHint|Qt::WindowContextHelpButtonHint);
    QWidget w(NULL,Qt::Window|Qt::WindowStaysOnBottomHint|Qt::WindowContextHelpButtonHint);

    QLabel l(&w);

    l.setText("I'm a label control.");
    w.setWindowTitle("D.T.Software");
    w.resize(400, 300);
    w.show();
    
    return a.exec();
}
