#include "Widget.h"
#include <QDir>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //该视图嵌入在Widget类中
    m_treeView.setParent(this);
    m_treeView.move(10, 10);
    m_treeView.resize(500, 300);

    m_fsModel.setRootPath(QDir::currentPath()); //从当前工作目录中取数据

    m_treeView.setModel(&m_fsModel); //连接模型与视图

    //设置树形视图的数据索引，从树形视图的根部开始显示工作目录中的内容
    m_treeView.setRootIndex(m_fsModel.index(QDir::currentPath()));
}

Widget::~Widget()
{
    
}
