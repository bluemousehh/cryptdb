#include "dialog.h"
#include "ui_dialog.h"
// #include <QProcess>
#include <QtCore>
#include <QtGui>
using namespace std;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{

    QProcess proc;
    // proc.setWorkingDirectory("~/");
    qDebug() << QDir::currentPath();
    proc.start("./main");

    QString input;
    input = ui->textEdit->toPlainText();
    input += "\n";
    qDebug() << qPrintable(input);
    //string st = string((const char *)input.toLocal8Bit());
    int a = proc.write(input.toAscii());

    // proc->close();
    proc.waitForFinished();

    QByteArray str = proc.readAll();
    ui->textEdit_output->clear();
    ui->textEdit_output->setText( QString::fromLocal8Bit(str) );
    qDebug() << str;
    // ui->textEdit->setText( QDir::currentPath());
    // ui->label->setText(QString(out));
}
