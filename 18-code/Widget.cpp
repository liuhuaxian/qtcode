#include "Widget.h"
#include "QLoginDialog.h"

#include <QDebug>

Widget::Widget(QWidget *parent) : QWidget(parent), TestBtn(this)
{
    TestBtn.setText("Test Login Dialog");

    setFixedSize(200, 50);

    connect(&TestBtn, SIGNAL(clicked()), this, SLOT(TestBtn_Clicked()));
}

void Widget::TestBtn_Clicked()
{
    QLoginDialog dlg;

    if( dlg.exec() == QDialog::Accepted ) //模态显示QLoginDialog对应的窗口
    {
        qDebug() << "User: " + dlg.getUser();
        qDebug() << "Pwd: " + dlg.getPwd();
    }
}

Widget::~Widget()
{
    
}
