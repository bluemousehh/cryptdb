/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Feb 27 18:54:35 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QTreeView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionStart_CryptDB;
    QAction *actionConnect_C;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter_3;
    QTreeView *treeView;
    QSplitter *splitter_2;
    QTableView *tableView;
    QSplitter *splitter;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(633, 464);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks|QMainWindow::ForceTabbedDocks);
        actionStart_CryptDB = new QAction(MainWindow);
        actionStart_CryptDB->setObjectName(QString::fromUtf8("actionStart_CryptDB"));
        actionConnect_C = new QAction(MainWindow);
        actionConnect_C->setObjectName(QString::fromUtf8("actionConnect_C"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        splitter_3 = new QSplitter(centralWidget);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        treeView = new QTreeView(splitter_3);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        splitter_3->addWidget(treeView);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        tableView = new QTableView(splitter_2);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        splitter_2->addWidget(tableView);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        plainTextEdit = new QPlainTextEdit(splitter);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        splitter->addWidget(plainTextEdit);
        pushButton = new QPushButton(splitter);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        splitter->addWidget(pushButton);
        splitter_2->addWidget(splitter);
        splitter_3->addWidget(splitter_2);

        horizontalLayout->addWidget(splitter_3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 633, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionStart_CryptDB);
        menuFile->addAction(actionConnect_C);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionStart_CryptDB->setText(QApplication::translate("MainWindow", "Start CryptDB (&S)", 0, QApplication::UnicodeUTF8));
        actionConnect_C->setText(QApplication::translate("MainWindow", "Connect (&C)", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File (&F)", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
