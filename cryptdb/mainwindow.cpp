#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDirModel>

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
