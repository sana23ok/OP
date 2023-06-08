#include "mainwindow.h"
#include "mytime.h"
#include "ui_mainwindow.h"
#include <exception>
#include <QString>
#include <QMessageBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QLayout>
#include <QFont>
#include <QWidget>

class TimeFormatException : public exception {
private:
    string message;

public:
    TimeFormatException(const string& msg) : message(msg) {}

    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

MyTime task(const string& timeString){
    istringstream iss(timeString);
    string token;
    string delimiter = ":";
    int hours, minutes, seconds;

    // Extract hours
    getline(iss, token, ':');
    hours = stoi(token);

    // Extract minutes
    getline(iss, token, ':');
    minutes = stoi(token);

    // Extract seconds
    getline(iss, token, ':');
    seconds = stoi(token);

    return MyTime(hours, minutes, seconds);
}


bool checker(QLineEdit* lineEdit, string &s){
    QString TextTime1 = lineEdit->text();
    string time1 = TextTime1.toStdString();
    bool valid_time1 = false;

    try {
        valid_time1 = message(time1);

        if (time1.empty()) {
            throw TimeFormatException("Field is empty!");
        }

        if (!valid_time1) {
            throw TimeFormatException("Format is not valid!");
        }

        s = time1;
        return true;
    } catch (const TimeFormatException& e) {
        std::cout << "Error: " << e.what() << std::endl;
        QMessageBox::critical(nullptr, "Incorrect format", e.what());
        return false;
    }
}

void MainWindow::on_AddButton_clicked()
{
    QLineEdit* lineEdit = findChild<QLineEdit*>("lineEdit");
    string timeString;

    if (count < 2) {
        if (checker(lineEdit, timeString)) {

            QLabel* label = new QLabel(QString::fromStdString(timeString));

            if(count<1){
                moment1 = task(timeString);
            }else{
                moment2 = task(timeString);
            }

            QScrollArea* scrollData = findChild<QScrollArea*>("scrollData");
            QFont textEditFont;
            textEditFont.setPointSize(12);
            label->setFont(textEditFont);
            if (scrollData) {
                QWidget* scrollDataWidget = scrollData->widget();
                QLayout* layout = scrollDataWidget->layout();
                if (!layout) {
                    layout = new QVBoxLayout(scrollDataWidget);
                    scrollDataWidget->setLayout(layout);
                }
                layout->addWidget(label);
            }

            count++;
        }
    } else {
        QMessageBox::critical(nullptr, "Error", "Only 2 dates are needed!");
    }
}

void MainWindow::on_ButtonRes_clicked()
{
    if (count < 2) {
        QMessageBox::critical(nullptr, "Error", "Please add two dates before calculating the result!");
        return;
    }

    bool isFirstPartOfDay1 = moment1.isInFirstPartOfDay();
    bool isFirstPartOfDay2 = moment2.isInFirstPartOfDay();

    QString res1 = "Moment [1] " + QString::fromStdString(moment1.get_time()) + " is in the first part of the day: ";
    if (isFirstPartOfDay1) {
        res1 += " Yes";
    } else {
        res1 += " No";
    }

    QString res2 = "Moment [2] " + QString::fromStdString(moment2.get_time()) + " is in the first part of the day: ";
    if (isFirstPartOfDay2) {
        res2 += " Yes";
    } else {
        res2 += " No";
    }

    QString combinedRes = res1 + "\n" + res2;

    QMessageBox msgBox;
    msgBox.setText(combinedRes);
    msgBox.setWindowTitle("Result");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setMinimumSize(400, 200);  // Set the minimum size of the QMessageBox

    msgBox.setStyleSheet("QMessageBox {"
                         "background-color: rgb(161, 189, 255);"
                         "border-style: solid;"
                         "border-width: 2px;"
                         "border-radius: 8px;"
                         "}"

                         "QMessageBox QPushButton {"
                         "background-color: rgb(65,105,226);"
                         "border-style: outset;"
                         "border-width: 1px;"
                         "border-radius: 8px;"
                         "min-width: 100px;"
                         "min-height: 40px;"
                         "}"

                         "QMessageBox QPushButton:pressed {"
                         "background-color: rgb(85, 120, 250);"
                         "}");


    QFont font = msgBox.font();
    font.setPointSize(12);
    msgBox.setFont(font);

    msgBox.exec();
}

void MainWindow::on_ButtonClearAll_clicked()
{
    // Clear the QLineEdit widget
    QLineEdit* lineEdit = findChild<QLineEdit*>("lineEdit");
    if (lineEdit) {
        lineEdit->clear();
    }

    // Clear the scrollData widget
    QScrollArea* scrollData = findChild<QScrollArea*>("scrollData");
    if (scrollData) {
        QWidget* scrollDataWidget = scrollData->widget();
        QLayout* layout = scrollDataWidget->layout();
        if (layout) {
            QLayoutItem* item;
            while ((item = layout->takeAt(0))) {
                delete item->widget();
                delete item;
            }
        }
    }

    // Clear the scrollAreaRes widget
    QScrollArea* scrollAreaRes = findChild<QScrollArea*>("scrollAreaRes");
    if (scrollAreaRes) {
        QWidget* scrollAreaResWidget = scrollAreaRes->widget();
        QLayout* layout = scrollAreaResWidget->layout();
        if (layout) {
            QLayoutItem* item;
            while ((item = layout->takeAt(0))) {
                delete item->widget();
                delete item;
            }
            delete layout; // Remove the existing layout
        }
        scrollAreaResWidget->setLayout(nullptr); // Set layout to nullptr
    }

    // Reset the counter to 0
    count = 0;
}

