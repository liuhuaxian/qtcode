#include <QCoreApplication>
#include <QImage>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QImage img;

    if( img.load("E:/github/qtcode/69-code/test.jpg") )
    {
        qDebug() << "image load ok";
        img = img.scaled(QSize(img.width() / 2, img.height() / 2));

        for(int i=0; i<img.width(); i++)
        {
            for(int j=0; j<img.height(); j++)
            {
                QRgb rgb = img.pixel(i, j);
                int r = qRed(rgb);
                int g = qGreen(rgb);
                int b = qBlue(rgb);
                int gray = (r + g + b) / 3;

                img.setPixel(i, j, qRgb(gray, gray, gray));
            }
        }

        img.save("new.jpg");
    }
    
    return a.exec();
}
