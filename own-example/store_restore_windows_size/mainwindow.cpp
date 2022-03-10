#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSettings>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/new/prefix1/clementine.ico"));
    readSettings();

}

bool MainWindow::event(QEvent *event)
{
    if (event->type()==QEvent::Close)
    {
        QSettings settings("MyCompany", "MyApp");
        settings.setValue("mytest/geometry", saveGeometry());
        settings.setValue("mytest/windowState", saveState());
        event->accept();
    }
    return QMainWindow::event(event);

}
void MainWindow::readSettings()
{
    QSettings settings("MyCompany", "MyApp");

    restoreGeometry(settings.value("mytest/geometry").toByteArray());
    restoreState(settings.value("mytest/windowState").toByteArray());
}

MainWindow::~MainWindow()
{
    delete ui;
}
