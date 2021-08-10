#include "MainWindow.h"
#include <QToolBar>
#include <QAction>
#include <QIcon>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    QToolBar* tb = addToolBar("Tool Bar");
    QAction* action = new QAction("", NULL);

    tb->setFloatable(false);
    tb->setMovable(false);

    action->setToolTip("Open");
    action->setIcon(QIcon(":/Res/open.png"));

    //添加动作到工具菜单栏中
    tb->addAction(action);

    QPushButton* b = new QPushButton("Button");
    QLabel* l = new QLabel("Label");
    QLineEdit* e = new QLineEdit();

    //添加组件到工具菜单栏中
    tb->addWidget(b);
    tb->addWidget(l);
    tb->addWidget(e);
}

MainWindow::~MainWindow()
{
    
}
