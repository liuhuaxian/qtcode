#include "Widget.h"
#include <QDebug>
#include <QStringList>
#include <QMessageBox>
#include <QFileDialog>
#include <QErrorMessage>
#include <QColorDialog>
#include <QFontDialog>
#include <QMessageBox>
#include <QWizard>
#include <QInputDialog>
#include <QProgressDialog>

Widget::Widget(QWidget *parent) : QWidget(parent),
    SimpleMsgBtn(this), CustomMsgBtn(this), OpenFileBtn(this),
    SaveFileBtn(this), ErrorMsgBtn(this), ColorMsgBtn(this),FontMsgBtn(this),
    InputMsgBtn(this), MessageBtn(this), WizardMsgBtn(this), ProgressMsgBtn(this)
{
    SimpleMsgBtn.setText("Simple Message Dialog");
    SimpleMsgBtn.move(20, 20);
    SimpleMsgBtn.resize(160, 30);

    CustomMsgBtn.setText("Custom Message Dialog");
    CustomMsgBtn.move(20, 70);
    CustomMsgBtn.resize(160, 30);

    OpenFileBtn.setText("Open File Dialog");
    OpenFileBtn.move(20, 120);
    OpenFileBtn.resize(160, 30);

    SaveFileBtn.setText("Save File Dialog");
    SaveFileBtn.move(20, 170);
    SaveFileBtn.resize(160, 30);

    ErrorMsgBtn.setText("Error Message Dialog");
    ErrorMsgBtn.move(20, 220);
    ErrorMsgBtn.resize(160, 30);

    ColorMsgBtn.setText("Color Select Dialog");
    ColorMsgBtn.move(20,270);
    ColorMsgBtn.resize(160,30);

    FontMsgBtn.setText("Font Select Dialog");
    FontMsgBtn.move(20,320);
    FontMsgBtn.resize(160,30);

    InputMsgBtn.setText("Input Message Dialog");
    InputMsgBtn.move(20,370);
    InputMsgBtn.resize(160,30);

    MessageBtn.setText("Message Dialog");
    MessageBtn.move(20,420);
    MessageBtn.resize(160,30);

    WizardMsgBtn.setText("Wizard Dialog");
    WizardMsgBtn.move(20,470);
    WizardMsgBtn.resize(160,30);

    ProgressMsgBtn.setText("Progress Message Dialog");
    ProgressMsgBtn.move(20,520);
    ProgressMsgBtn.resize(160,30);

    //resize(200, 220);
    //setFixedSize(200, 220);


    connect(&SimpleMsgBtn, SIGNAL(clicked()), this, SLOT(SimpleMsgBtn_Clicked()));
    connect(&CustomMsgBtn, SIGNAL(clicked()), this, SLOT(CustomMsgBtn_Clicked()));
    connect(&OpenFileBtn, SIGNAL(clicked()), this, SLOT(OpenFileBtn_Clicked()));
    connect(&SaveFileBtn, SIGNAL(clicked()), this, SLOT(SaveFileBtn_Clicked()));
    connect(&ErrorMsgBtn, SIGNAL(clicked()), this, SLOT(ErrorMsgBtn_Clicked()));
    connect(&ColorMsgBtn, SIGNAL(clicked()), this, SLOT(ColorMsgBtn_Clicked()));
    connect(&FontMsgBtn, SIGNAL(clicked()), this, SLOT(FontMsgBtn_Clicked()));
    connect(&InputMsgBtn, SIGNAL(clicked()), this, SLOT(InputMsgBtn_Clicked()));
    connect(&MessageBtn, SIGNAL(clicked()), this, SLOT(MessageBtn_Clicked()));
    connect(&WizardMsgBtn, SIGNAL(clicked()), this, SLOT(WizardMsgBtn_Clicked()));
    connect(&ProgressMsgBtn, SIGNAL(clicked()), this, SLOT(ProgressMsgBtn_Clicked()));
}

void Widget::SimpleMsgBtn_Clicked()
{
    QMessageBox msg(this);

    msg.setText("This is a message dialog!");

    msg.exec();
}

void Widget::CustomMsgBtn_Clicked()
{
    QMessageBox msg(this);

    msg.setWindowTitle("Window Title");
    msg.setText("This is a detail message dialog!");
    msg.setIcon(QMessageBox::Information);
    msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel | QMessageBox::YesToAll);

    if( msg.exec() == QMessageBox::Ok )
    {
        qDebug() << "Ok button is clicked!";
    }
}

void Widget::OpenFileBtn_Clicked()
{
    QFileDialog dlg(this);

    dlg.setAcceptMode(QFileDialog::AcceptOpen);
    //dlg.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    QStringList filters;
    filters << "Image files (*.png *.xpm *.jpg)"
            << "Text files (*.txt)"
            << "Any files (*)";
    dlg.setNameFilters(filters);
    //dlg.setNameFilter("Text(*.txt)");
    dlg.setFileMode(QFileDialog::ExistingFiles);
    //设置显示在窗口中的文件
    dlg.setFileMode(QFileDialog::ExistingFile);

    if( dlg.exec() == QFileDialog::Accepted )
    {
        QStringList fs = dlg.selectedFiles();

        for(int i=0; i<fs.count(); i++)
        {
            qDebug() << fs[i];
        }
    }
}

void Widget::SaveFileBtn_Clicked()
{
    QFileDialog dlg(this);

    dlg.setAcceptMode(QFileDialog::AcceptSave);
    //dlg.setFilter("Text(*.txt)");
    dlg.setFilter(QDir::Files);

    if( dlg.exec() == QFileDialog::Accepted )
    {
        QStringList fs = dlg.selectedFiles();

        for(int i=0; i<fs.count(); i++)
        {
            qDebug() << fs[i];
        }
    }
}
void Widget::ErrorMsgBtn_Clicked()
{
    QErrorMessage dlg(this);
    qDebug() << "In ErrorMsgBtn_clicked()";
    dlg.showMessage("错误");
    dlg.exec();
}
void Widget::ColorMsgBtn_Clicked()
{
    QColorDialog dlg(this);

    dlg.setWindowTitle("Color Editor");
    dlg.setCurrentColor(QColor(100, 111, 222));

    if( dlg.exec() == QColorDialog::Accepted )
    {
        QColor color = dlg.selectedColor();

        qDebug() << color;
        qDebug() << color.red();
        qDebug() << color.green();
        qDebug() << color.blue();
        qDebug() << color.hue();
        qDebug() << color.saturation();
        qDebug() << color.value();
    }
}
void Widget::FontMsgBtn_Clicked()
{
    qDebug() << "void FontMsgBtn_Clicked();";
    QFontDialog dlg;
    if (dlg.exec() == QFontDialog::Accepted )
    {
        QFont ft = dlg.selectedFont();
        qDebug() << ft;
    }

}

void Widget::InputMsgBtn_Clicked()
{
    QInputDialog dlg(this);

    dlg.setWindowTitle("Input Test");
    dlg.setLabelText("Please input an integer:");
    dlg.setInputMode(QInputDialog::TextInput);


    if( dlg.exec() == QInputDialog::Accepted )
    {
        qDebug() << dlg.textValue();
    }
}

void Widget::MessageBtn_Clicked()
{
    qDebug() << "void Widget::MessageBtn_Clicked()";
    QMessageBox dlg;
    dlg.setText("this is messagebox");
    dlg.exec();
}

void Widget::WizardMsgBtn_Clicked()
{
    qDebug() << "void Widget::WizardMsgBtn_Clicked()";
    QWizard dlg;
    dlg.exec();
}

void Widget::ProgressMsgBtn_Clicked()
{
    QProgressDialog dlg(this);

    dlg.setWindowTitle("Updating...");
    dlg.setLabelText("Downloading update from server...");
    dlg.setMinimum(0);
    dlg.setMaximum(100);
    dlg.setValue(35);

    // create a new thread

    dlg.exec();
}

void Widget::show()
{
    QWidget::show(); //非阻塞显示。
    setFixedSize(this->width(), this->height()); //固定主窗口大小
}
Widget::~Widget()
{
    
}
