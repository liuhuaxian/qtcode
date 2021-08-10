#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
  lineEdit(this), plainEdit(this), textEdit(this)
{
    resize(600, 420);

    //单行文本编辑器
    lineEdit.move(20, 20);
    lineEdit.resize(560, 100);
    lineEdit.insert("QLineEdit");
    lineEdit.insert("\n");
    lineEdit.insert("<img src=\"E:\\github\\qtcode\\30-code\\1\\D.T.png\" />");

    //多行普通文本编辑器
    plainEdit.move(20, 130);
    plainEdit.resize(560, 130);
    plainEdit.insertPlainText("QPlainTextEdit");
    plainEdit.insertPlainText("\n");
    plainEdit.insertPlainText("<img src=\"E:\\github\\qtcode\\30-code\\1\\D.T.png\" />");

    //多行富文本编辑器
    textEdit.move(20, 270);
    textEdit.resize(560, 130);
    textEdit.insertPlainText("QTextEdit");
    textEdit.insertPlainText("\n");
    //可正常解析出图片
    textEdit.insertHtml("<img src=\"E:\\github\\qtcode\\30-code\\1\\D.T.png\" />");
}

MainWindow::~MainWindow()
{
    
}
