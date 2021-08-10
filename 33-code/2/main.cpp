#include <QtCore/QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDataStream>
#include <QDebug>

void text_stream_test(QString f)
{
    QFile file(f);

    if( file.open(QIODevice::WriteOnly | QIODevice::Text) )
    {
        QTextStream out(&file);

        out << QString("D.T.Software") << endl;
        out << QString("Result: ") << endl;
        out << 5 << '*' << 6 << '=' << 5 * 6 << endl;

        file.close();
    }

    if( file.open(QIODevice::ReadOnly | QIODevice::Text) )
    {
        QTextStream in(&file);

        while( !in.atEnd() )
        {
            QString line = in.readLine();

            qDebug() << line;
        }

        file.close();
    }
}


void data_stream_test(QString f)
{
    QFile file(f);

    if( file.open(QIODevice::WriteOnly) )
    {
        QDataStream out(&file);

        //指定qt版本，可能不同版本之间在实现数据流上有差别
        out.setVersion(QDataStream::Qt_4_7);

        out << QString("D.T.Software");
        out << QString("Result: ");
        out << 3.14;

        file.close();
    }

    if( file.open(QIODevice::ReadOnly) )
    {
        QDataStream in(&file);
        QString dt = "";
        QString result = "";
        double value = 0;

        in.setVersion(QDataStream::Qt_4_7);

        in >> dt;
        in >> result;
        in >> value;

        file.close();

        qDebug() << dt;
        qDebug() << result;
        qDebug() << value;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    text_stream_test("C:/Users/lhx/Desktop/text.txt");
    data_stream_test("C:/Users/lhx/Desktop/data.dat");
    
    return a.exec();
}
