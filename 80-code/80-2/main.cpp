#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QThread>
#include "FileWriter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "main() tid = " << QThread::currentThreadId();

    FileWriter writer("C:/Users/lhx/Desktop/test.txt");

    if( writer.open() )
    {
        writer.write("D.T.Software\r\n");
        writer.write("���Ĳ���\r\n");
        writer.write("��̩���\r\n");
        writer.close();
    }

    return a.exec();
}
