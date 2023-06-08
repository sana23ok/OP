#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mytime.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_ButtonClearAll_clicked();
    void on_AddButton_clicked();
    void on_ButtonRes_clicked();


private:
    Ui::MainWindow *ui;
    int count=0;
    MyTime moment1, moment2;
};
#endif // MAINWINDOW_H
