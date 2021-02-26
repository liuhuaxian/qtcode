#include "Widget.h"
#include <QPlainTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_tabWidget.setParent(this);
    m_tabWidget.move(10, 10);
    m_tabWidget.resize(200, 200);
    m_tabWidget.setTabPosition(QTabWidget::North);//标签的位置
    m_tabWidget.setTabShape(QTabWidget::Rounded);//标签的形状
    m_tabWidget.setTabsClosable(true); //设置标签是否可关闭

    QPlainTextEdit* edit = new QPlainTextEdit(&m_tabWidget);
    edit->insertPlainText("1st Tab Page");

    m_tabWidget.addTab(edit, "1st");

    QWidget* widget = new QWidget(&m_tabWidget);
    QVBoxLayout* layout = new QVBoxLayout();
    QLabel* lbl = new QLabel(widget);
    QPushButton* btn = new QPushButton(widget);

    lbl->setText("2nd Tab Page");
    lbl->setAlignment(Qt::AlignCenter);

    btn->setText("2nd Tab Page");

    layout->addWidget(lbl);
    layout->addWidget(btn);

    widget->setLayout(layout);

    m_tabWidget.addTab(widget, "2nd");

    m_tabWidget.setCurrentIndex(0);//设置当前显示的窗口号，以0开始

    connect(&m_tabWidget, SIGNAL(currentChanged(int)), this, SLOT(onTabCurrentChanged(int)));
    connect(&m_tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(onTabCloseRequested(int)));
}

void Widget::onTabCurrentChanged(int index)
{
    qDebug() << "Page change to: " << index;
}

void Widget::onTabCloseRequested(int index)
{
    m_tabWidget.removeTab(index);
}

Widget::~Widget()
{
    
}
