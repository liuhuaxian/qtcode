#include <QtCore/QCoreApplication>
#include <QDebug>

class MObj : public QObject
{
    QString m_name;
public:
    MObj(const QString& name)
    {
        m_name = name;

        qDebug() << "Constructor: " << m_name;
    }

    ~MObj()
    {
        qDebug() << "Destructor: " << m_name;
    }
};

void fcTest()
{
    QObject* p = new QObject();
    QObject* c1 = new QObject();
    QObject* c2 = new QObject();

    c1->setParent(p);
    c2->setParent(p);

    qDebug() << "c1: " << c1;
    qDebug() << "c2: " << c2;

    const QObjectList& list = p->children();

    for(int i=0; i<list.length(); i++)
    {
        qDebug() << list[i];
    }

    qDebug() << "p: " << p;

    qDebug() << "c1 parent: " << c1->parent();
    qDebug() << "c2 parent: " << c2->parent();
}

void delTest()
{
    MObj* obj1 = new MObj("obj1");
    MObj* obj2 = new MObj("obj2");
    MObj* obj3 = new MObj("obj3");
    MObj* obj4 = new MObj("obj4");

    obj2->setParent(obj1);
    obj3->setParent(obj1);
    obj4->setParent(obj3);

    delete obj3;

    const QObjectList& list = obj1->children();

    qDebug() << "obj2: " << obj2;

    for(int i=0; i<list.length(); i++)
    {
        qDebug() << list[i];
    }

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    fcTest();
    delTest();
    
    return a.exec();
}
