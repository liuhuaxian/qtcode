#include <QtCore/QCoreApplication>
#include "Watcher.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Watcher watcher;

    //当指定的文件或目录发生变化的时候触发相应的信号。
    watcher.addPath("C:/Users/lhx/Desktop/data.dat");
    watcher.addPath("C:/Users/lhx/Desktop/qtcode");
    
    return a.exec();
}
