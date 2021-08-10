#include "MainWindow.h"
#include <QMenu>

MainWindow::MainWindow()
{

}

MainWindow* MainWindow::NewInstance()
{
    MainWindow* ret = new MainWindow();

    if( (ret == NULL) || !ret->construct() )
    {
        delete ret;
        ret = NULL;
    }

    return ret;
}

bool MainWindow::construct()
{
    bool ret = true;

    ret = ret && initMenuBar();

    return ret;
}

bool MainWindow::initMenuBar()
{
    bool ret = true;
    QMenuBar* mb = menuBar();

    ret = ret && initFileMenu(mb);

    return ret;
}

bool MainWindow::initFileMenu(QMenuBar* mb)
{
    QMenu* menu = new QMenu("File(&F)");
    bool ret = (menu != NULL);

    if( ret )
    {
        QAction* action = NULL;

        ret = ret && makeAction(action, "New(N)", Qt::CTRL + Qt::Key_N);

        if( ret )
        {
            menu->addAction(action);    // add Action item to Menu
        }

        menu->addSeparator();       //在在菜单下面添加分割线。

        ret = ret && makeAction(action, "Exit(X)", Qt::CTRL + Qt::Key_X);

        if( ret )
        {
            menu->addAction(action);    // add Action item to Menu
        }
    }

    if( ret )
    {
        mb->addMenu(menu);    // add Menu add to application Menu Bar
    }
    else
    {
        delete menu;
    }


    return ret;
}

//构建动作对象，并创建快捷键。
bool MainWindow::makeAction(QAction*& action, QString text, int key)
{
    bool ret = true;

    action = new QAction(text, NULL);

    if( action != NULL )
    {
        action->setShortcut(QKeySequence(key)); //添加快捷键
    }
    else
    {
        ret = false;
    }

    return ret;
}

MainWindow::~MainWindow()
{
    
}
