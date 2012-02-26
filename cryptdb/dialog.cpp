#include "dialog.h"
#include "ui_dialog.h"
// #include <QProcess>
#include <QtCore>
#include <QtGui>

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
    // qDebug() << QDir::currentPath();
    proc.start("./main");
    proc.waitForFinished();

    QString s;
    s = ui->textEdit->toPlainText();
    s += "\n";
    proc.write(qPrintable(s));

    // proc->close();
    QByteArray str = proc.readAll();
    ui->textEdit->setText( QString::fromLocal8Bit(str) );
    qDebug() << str;
    // ui->textEdit->setText( QDir::currentPath());
    // ui->label->setText(QString(out));
}
