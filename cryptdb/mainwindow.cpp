#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // QAbstractItemModel* dbModel = new QAbstractItemModel();
    QDirModel* dbModel = new QDirModel(this);
    ui->treeView->setModel (dbModel);

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

        input = QString("killall -9 mysql-proxy");
        proxyProc->start(input);
        proxyProc->waitForFinished();
        //input = QString("killall -9 mysql");
        //proxyProc->start(input);
        //proxyProc->waitForFinished();

        QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
        env.insert("EDBDIR", "/home/hh/Documents/FYP/Project/cryptdb/obj"); // Add an environment variable
        proxyProc->setProcessEnvironment(env);

        input = QString("mysql-proxy --plugins=proxy --event-threads=4 --max-open-files=1024 --proxy-lua-script=/home/hh/Documents/FYP/Project/cryptdb/mysqlproxy/wrapper.lua --proxy-address=127.0.0.1:3307 --proxy-backend-addresses=localhost:3306");
        proxyProc->start(input);

        //QByteArray str = proxyProc->readAll();
        //qDebug() << str;

    } catch (std::exception& e) {
        qDebug() << e.what();
    }

}

void MainWindow::on_actionConnect_C_triggered()
{
    try {
        db = new QSqlDatabase(QSqlDatabase::addDatabase("QMYSQL"));
        db->setDatabaseName("cryptdbtest");
        db->setHostName("127.0.0.1");
        db->setPort(3306);
        db->setUserName("root");
        db->setPassword("letmein");
        if (! db->open()) {
            QSqlError e = db->lastError();
            qFatal("ServerDB db1: Failed initialization: %s",qPrintable(e.text()));
            return;
        }

        QSqlQuery query;
        query.exec("DROP TABLE t2");
        query.exec("CREATE TABLE t2 (id integer primary key, name text, salary integer)");
        query.exec("INSERT INTO t2 VALUES (1, 'alice', 100)");
        query.exec("INSERT INTO t2 VALUES (2, 'bob', 200)");
        query.exec("INSERT INTO t2 VALUES (0, 'chris', 0)");

        //QSqlQueryModel *model = new QSqlQueryModel;
        //model->setQuery("SELECT * FROM t2");
        //QTableView *view = new QTableView;
        //view->setModel(model);
        //view->show();

        model = new QSqlTableModel(this);
        model->setTable("t2");
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model->select();

        ui->tableView->setModel(model);


    } catch (std::exception &e) {
        qDebug() << e.what() ;
    }

}


void MainWindow::on_pushButton_2_clicked()
{
    model->database().transaction();
    if (model->submitAll()) {
        model->database().commit();
    } else {
        model->database().rollback();
        QMessageBox::warning(this, "tableModel", tr("Database Error: %1").arg(model->lastError().text()));
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    model->revertAll();
}

void MainWindow::on_pushButton_clicked()
{
    /*
    QString q = ui->plainTextEdit->toPlainText();
    QSqlQuery query = model->query();
    if (!query.exec(q))
        QMessageBox::warning(this, "tableModel", tr("Query Error: %1").arg(model->lastError().text()));
    else {
        // model->select();
        QTableView *view = new QTableView;
        view->setModel(model);
        view->show();
    }
    */

    QString q = ui->plainTextEdit->toPlainText().trimmed();
    // QSqlQuery query = model->query();
    QSqlQueryModel *mod = new QSqlQueryModel();
    // mod->setQuery(q);
    //mod->setQuery(q);
    QSqlQuery query = mod->query();

    // if (!mod.exec(q))
    if (!query.exec(q))
        QMessageBox::warning(this, "tableModel", tr("Query Error: %1").arg(mod->lastError().text()));
    else {
        if (q.toLower().startsWith("select"))
        {
            QTableView *view = new QTableView;
            view->setModel(mod);
            view->show();
        }
        model->select();
    }




}
