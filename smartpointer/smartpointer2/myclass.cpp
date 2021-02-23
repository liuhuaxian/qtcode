#include <QString>
#include <QDebug>
#if 0   // MyClass 原始版本
class MyClass {
public:
    MyClass(){}
    MyClass(const MyClass &other) {
        m_id = other.GetId();
        m_path = other.GetPath();
    }
    ~MyClass(){}

    int GetId() const { return m_id; }
    void SetId(int val) { m_id = val; }
    QString GetPath() const { return m_path; }
    void SetPath(QString val) { m_path = val; }
private:
    int m_id = -1;
    QString m_path;
};

#else
// MyClass 支持隐式共享
// 1. 将 MyClass 的所有数据成员都放到 MyClassData 中.
// 2. 在 MyClass 中维护一个 QSharedDataPointer<MyClassData> d.
// 3. MyClass 中通过 d-> 的形式访问数据.
// 4. MyClassData 继承自 QSharedData.

#include <QSharedData>
#include <QSharedDataPointer>
class MyClassData : public QSharedData
{
public:
    MyClassData()
    {
        qDebug()<<"in  MyClassData()";
    }
    MyClassData(const MyClassData &other)
        : QSharedData(other), id(other.id), path(other.path)
    {
        qDebug() << "in MyClassData(const MyClassData &other)";
    }
    ~MyClassData(){
        qDebug() << "in ~MyClassData()";
    }

    int id = -1;
    QString path;
};

class MyClass {
public:
    MyClass()
    {
        d = new MyClassData();
        qDebug() << "in MyClass()";
    }
    MyClass(int id, const QString & path) {
        d = new MyClassData();
        SetId(id);
        SetPath(path);
    }

    MyClass(const MyClass &other) : d(other.d) //这个d(other.d)是关键。
    {
        qDebug() << "in MyClass(const MyClass &other)";
    }

    ~MyClass(){}

    int GetId() const { return d->id; }
    void SetId(int val) { d->id = val; }
    QString GetPath() const { return d->path; }
    void SetPath(QString val) { d->path = val; }
private:
    QSharedDataPointer<MyClassData> d;
};
#endif

