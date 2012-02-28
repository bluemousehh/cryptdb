#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionStart_CryptDB_triggered();

    void on_actionConnect_C_triggered();

private:
    Ui::MainWindow *ui;
    QProcess *proxyProc;
};

#endif // MAINWINDOW_H
