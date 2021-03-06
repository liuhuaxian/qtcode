#include "MainWindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>

void MainWindow::showErrorMessage(QString message)
{
    QMessageBox msg(this);

    msg.setWindowTitle("Error");
    msg.setText(message);
    msg.setIcon(QMessageBox::Critical);//设置代表消息的级别图标
    msg.setStandardButtons(QMessageBox::Ok);

    msg.exec();
}

//选择打开的文本，并以字串的方式返回
QString MainWindow::showFileDialog(QFileDialog::AcceptMode mode, QString title)
{
    QString ret = "";
    QFileDialog fd(this);
    QStringList filters;

    filters.append("Text Files (*.txt)");
    filters.append("All Files (*)");

    fd.setWindowTitle(title);
    fd.setAcceptMode(mode);
    //fd.setFilters(filters);//qt5中不支持该函数
    fd.setNameFilters(filters);

    if( mode == QFileDialog::AcceptOpen )
    {
        fd.setFileMode(QFileDialog::ExistingFile);
    }

    if( fd.exec() == QFileDialog::Accepted )
    {
        //只返回一个文件名，及该文件编辑器只支持打开一个文件。
        ret = fd.selectedFiles()[0];
    }

    return ret;
}

void MainWindow::onFileOpen()
{
    QString path = showFileDialog(QFileDialog::AcceptOpen, "Open");

    if( path != "" )
    {
        QFile file(path);

        if( file.open(QIODevice::ReadOnly | QIODevice::Text) )
        {
            mainEditor.setPlainText(QString(file.readAll()));

            file.close();

            m_filePath = path;

            setWindowTitle("NotePad - [ " + m_filePath + " ]");
        }
        else
        {
            showErrorMessage(QString("Open file error! \n\n") + "\"" + path + "\"");
        }
    }
}


void MainWindow::onFileSave()
{
    if( m_filePath == "" )
    {
        m_filePath = showFileDialog(QFileDialog::AcceptSave, "Save");
    }

    if( m_filePath != "" )
    {
        QFile file(m_filePath);

        if( file.open(QIODevice::WriteOnly | QIODevice::Text) )
        {
            QTextStream out(&file);

            out << mainEditor.toPlainText();

            file.close();

            setWindowTitle("NotePad - [ " + m_filePath + " ]");
        }
        else
        {
            showErrorMessage(QString("Save file error! \n\n") + "\"" + m_filePath + "\"");

            m_filePath = "";
        }
    }
}

void MainWindow::onFileSaveAs()
{
    QString path = showFileDialog(QFileDialog::AcceptSave, "Save As");

    if( path != "" )
    {
        QFile file(path);

        if( file.open(QIODevice::WriteOnly | QIODevice::Text) )
        {
            QTextStream out(&file);

            out << mainEditor.toPlainText();

            file.close();

            m_filePath = path;

            setWindowTitle("NotePad - [ " + m_filePath + " ]");
        }
        else
        {
            showErrorMessage(QString("Save file error! \n\n") + "\"" + path + "\"");
        }
    }
}
