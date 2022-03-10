/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_5;
    QSplitter *splitterMain;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QTreeView *treeView;
    QSplitter *splitter;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QListView *listView;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *LabFileName;
    QLabel *LabFileSize;
    QLabel *LabType;
    QCheckBox *chkIsDir;
    QLabel *LabPath;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(900, 559);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_5 = new QVBoxLayout(centralWidget);
        verticalLayout_5->setSpacing(3);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(3, 3, 3, 3);
        splitterMain = new QSplitter(centralWidget);
        splitterMain->setObjectName(QString::fromUtf8("splitterMain"));
        splitterMain->setOrientation(Qt::Horizontal);
        groupBox_3 = new QGroupBox(splitterMain);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setSpacing(4);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(4, 4, 4, 4);
        treeView = new QTreeView(groupBox_3);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        verticalLayout_3->addWidget(treeView);

        splitterMain->addWidget(groupBox_3);
        splitter = new QSplitter(splitterMain);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(4);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        listView = new QListView(groupBox);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout->addWidget(listView);

        splitter->addWidget(groupBox);
        groupBox_2 = new QGroupBox(splitter);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(4, 4, 4, 4);
        tableView = new QTableView(groupBox_2);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_2->addWidget(tableView);

        splitter->addWidget(groupBox_2);
        splitterMain->addWidget(splitter);

        verticalLayout_5->addWidget(splitterMain);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMaximumSize(QSize(16777215, 100));
        verticalLayout_4 = new QVBoxLayout(groupBox_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LabFileName = new QLabel(groupBox_4);
        LabFileName->setObjectName(QString::fromUtf8("LabFileName"));

        horizontalLayout->addWidget(LabFileName);

        LabFileSize = new QLabel(groupBox_4);
        LabFileSize->setObjectName(QString::fromUtf8("LabFileSize"));

        horizontalLayout->addWidget(LabFileSize);

        LabType = new QLabel(groupBox_4);
        LabType->setObjectName(QString::fromUtf8("LabType"));

        horizontalLayout->addWidget(LabType);

        chkIsDir = new QCheckBox(groupBox_4);
        chkIsDir->setObjectName(QString::fromUtf8("chkIsDir"));

        horizontalLayout->addWidget(chkIsDir);


        verticalLayout_4->addLayout(horizontalLayout);

        LabPath = new QLabel(groupBox_4);
        LabPath->setObjectName(QString::fromUtf8("LabPath"));

        verticalLayout_4->addWidget(LabPath);


        verticalLayout_5->addWidget(groupBox_4);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 23));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266\347\263\273\347\273\237Model/View", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "TreeView", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "ListView", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "TableView", nullptr));
        groupBox_4->setTitle(QString());
        LabFileName->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\345\220\215\357\274\232", nullptr));
        LabFileSize->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\345\244\247\345\260\217\357\274\232", nullptr));
        LabType->setText(QApplication::translate("MainWindow", "\350\212\202\347\202\271\347\261\273\345\236\213\357\274\232", nullptr));
        chkIsDir->setText(QApplication::translate("MainWindow", "\350\212\202\347\202\271\346\230\257\347\233\256\345\275\225", nullptr));
        LabPath->setText(QApplication::translate("MainWindow", "\350\267\257\345\276\204\345\220\215\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
