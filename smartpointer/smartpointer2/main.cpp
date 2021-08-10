#include <QDebug>
#include "myclass.cpp"

int main()
{

    MyClass t;
    MyClass t2(t);

    qDebug() << t2.GetId();
    qDebug() << t.GetId();

    //此处会触发写时复制
    t2.SetId(2);
    qDebug() << t2.GetId();
    qDebug() << t.GetId();
    while (1) {}
    return 0;
}
