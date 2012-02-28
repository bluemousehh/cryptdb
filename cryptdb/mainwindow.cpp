#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDirModel>
#include <QtCore>
#include <QtGui>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // QAbstractItemModel* dbModel = new QAbstractItemModel();
    QDirModel* dbModel = new QDirModel(this);
    ui->treeView->setModel (dbModel);

    // this->on_actionStart_CryptDB_triggered();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionStart_CryptDB_triggered()
{
    try {
        proxyProc = new QProcess();
        QString input;

        //input = QString("\"netstat -anp | grep 3307\"");
        //proxyProc->start(input);
        //proxyProc->waitForFinished();
        //qDebug() << proxyProc->readAll();


        input = QString("killall -9 mysql-proxy");
        proxyProc->start(input);
        proxyProc->waitForFinished();
        //input = QString("killall -9 mysql");
        //proxyProc->start(input);
        //proxyProc->waitForFinished();

        QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
        env.insert("EDBDIR", "/home/hh/Documents/FYP/Project/cryptdb/obj"); // Add an environment variable
        // env.insert("PATH", env.value("Path") + ";C:\\Bin");
        proxyProc->setProcessEnvironment(env);
        // proxyProc->start(QString("\echo $PATH\""));
        // proxyProc->waitForReadyRead();
        // qDebug() << proxyProc->readAll();
        // QString EDBDIR= QString("\"/home/hh/Documents/FYP/Project/cryptdb/obj\'");
        // input = QString("export EDBDIR=/home/hh/Documents/FYP/Project/cryptdb/obj");
        //proxyProc->start(input, QStringList() << "");
        // proxyProc->start(input);
        // proxyProc->waitForFinished();


        // input = QString("mysql-proxy --plugins=proxy --event-threads=4 --max-open-files=1024 --proxy-lua-script=$EDBDIR/../mysqlproxy/wrapper.lua --proxy-address=127.0.0.1:3307 --proxy-backend-addresses=localhost:3306");
        input = QString("mysql-proxy --plugins=proxy --event-threads=4 --max-open-files=1024 --proxy-lua-script=/home/hh/Documents/FYP/Project/cryptdb/mysqlproxy/wrapper.lua --proxy-address=127.0.0.1:3307 --proxy-backend-addresses=localhost:3306");
        proxyProc->start(input);
        // proxyProc->waitForFinished();
        //proxyProc->waitForReadyRead(2000);

        QByteArray str = proxyProc->readAll();
        qDebug() << str;

    } catch (std::exception& e) {
        qDebug() << e.what();
    }

}

void MainWindow::on_actionConnect_C_triggered()
{
    try {
        QSqlDatabase *db = new QSqlDatabase(QSqlDatabase::addDatabase("QMYSQL"));
        db->setDatabaseName("cryptdbtest");
        db->setHostName("127.0.0.1");
        db->setPort(3307);
        db->setUserName("root");
        db->setPassword("letmein");
        if (! db->open()) {
            QSqlError e = db->lastError();
            qFatal("ServerDB db1: Failed initialization: %s",qPrintable(e.text()));
            return;
        }

        QSqlQueryModel model;

        model.setQuery("show databases;");
        ui->tableView->setModel(&model) ;


    } catch (std::exception &e) {
        qDebug() << e.what() ;
    }

}

