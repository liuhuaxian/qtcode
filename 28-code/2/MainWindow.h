#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include <QMainWindow>
#include <QKeySequence>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    MainWindow();
    MainWindow(const MainWindow&);
    MainWindow& operator= (const MainWindow&);

    bool construct();
    bool initMenuBar();
    bool initToolBar();
    bool initFileMenu(QMenuBar* mb);
    bool initEditMenu(QMenuBar* mb);
    bool initFormatMenu(QMenuBar* mb);
    bool initViewMenu(QMenuBar* mb);
    bool initHelpMenu(QMenuBar* mb);
    bool initFileToolItem(QToolBar* tb);
    bool makeAction(QAction*& action, QString text, int key);
    bool makeAction(QAction*& action, QString tip, QString icon);
public:
    static MainWindow* NewInstance();
    ~MainWindow();
};

#endif // _MAINWINDOW_H_
