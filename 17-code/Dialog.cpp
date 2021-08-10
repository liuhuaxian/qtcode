#include "Dialog.h"

#include <QDebug>

Dialog::Dialog(QWidget *parent) :
        QDialog(parent), ModalBtn(this), NormalBtn(this), MixedBtn(this)
{
    ModalBtn.setText("Modal Dialog");
    ModalBtn.move(20, 20);
    ModalBtn.resize(100, 30);

    NormalBtn.setText("Normal Dialog");
    NormalBtn.move(20, 70);
    NormalBtn.resize(100, 30);

    MixedBtn.setText("Mixed Dialog");
    MixedBtn.move(20, 120);
    MixedBtn.resize(100, 30);

    connect(&ModalBtn, SIGNAL(clicked()), this, SLOT(ModalBtn_Clicked()));
    connect(&NormalBtn, SIGNAL(clicked()), this, SLOT(NormalBtn_Clicked()));
    connect(&MixedBtn, SIGNAL(clicked()), this, SLOT(MixedBtn_Clicked()));

    resize(140, 170);
}

void Dialog::ModalBtn_Clicked()
{
    qDebug() << "ModalBtn_Clicked() Begin";

    QDialog dialog(this);

    dialog.exec(); //阻塞执行流，同时也阻止代码继续往下执行，除非用户在该窗口上执行了点击操作。

    //done(Accepted);  //那个对话框类实体调用done则关闭那个对话框。

    qDebug() << "ModalBtn_Clicked() End";
}

void Dialog::NormalBtn_Clicked()
{
    qDebug() << "NormalBtn_Clicked() Begin";

    QDialog* dialog = new QDialog(this);

    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show(); //不阻止对父窗口的操作，同时执行流也正常往下走

   // done(Rejected);

    qDebug() << "NormalBtn_Clicked() End";
}

void Dialog::MixedBtn_Clicked()
{
    qDebug() << "MixedBtn_Clicked() Begin";

    QDialog* dialog = new QDialog(this);

    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->setModal(true); //当前窗口阻止对父窗口的操作，但不阻塞代码执行流
    dialog->show();

    // done(100);

    qDebug() << "MixedBtn_Clicked() End";
}

Dialog::~Dialog()
{
    qDebug() << "~Dialog()";
}
