#include <QtGui/QApplication>
#include <QtSql>
#include "mainwindow.h"
#include "dialog.h"
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //Dialog w;
    w.show();

    return a.exec();
}
