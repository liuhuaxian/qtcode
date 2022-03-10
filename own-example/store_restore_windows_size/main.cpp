#include "mainwindow.h"
#include <QApplication>
#include <QStandardPaths>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
   // w.setWindowIcon(QIcon(":/new/prefix1/clementine.ico"));
    w.show();
    a.setWindowIcon(QIcon(":/new/prefix1/clementine.ico"));
   qDebug() << QString("%1/%2").arg(
              QStandardPaths::writableLocation(QStandardPaths::ConfigLocation),
              QCoreApplication::organizationName());

    return a.exec();
}
