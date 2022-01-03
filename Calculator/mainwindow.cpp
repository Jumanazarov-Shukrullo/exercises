#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpressionMatch>

double calcValue = 0.0;
bool divTrigger = false;
bool mulTrigger = false;
bool addTrigger = false;
bool subTrigger = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Display->setText(QString::number(calcValue));
    QPushButton *numButtons[10];
    for(int i = 0; i < 10; ++i) {
        QString butName = "Button" + QString::number(i);
        numButtons[i] = MainWindow::findChild<QPushButton*>(butName);
        connect(numButtons[i], SIGNAL(released()), this,
                SLOT(NumPressed()));
    }

    connect(ui->Add, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Subtract, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Multiply, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Divide, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Equal, SIGNAL(released()), this,
            SLOT(EqualButton()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::NumPressed() {
        QPushButton *button = (QPushButton *)sender();
        QString butVal = button->text();
        QString displayVal = ui->Display->text();
        if((displayVal.toDouble() == 0) || (displayVal.toDouble() == 0.0)){
            ui->Display->setText(butVal);
        } else {
            QString newVal = displayVal + butVal;
            double dblNewVal = newVal.toDouble();
            ui->Display->setText(QString::number(dblNewVal, 'g', 16));
        }
}

void MainWindow::MathButtonPressed() {
    divTrigger = false;
    mulTrigger = false;
    addTrigger = false;
    subTrigger = false;
    QString displayVal = ui->Display->text();
    calcValue = displayVal.toDouble();
    QPushButton *button = (QPushButton*)(sender());
    QString butVal = button->text();
    if (QString::compare(butVal, "/", Qt::CaseSensitive) == 0) {
        divTrigger = true;
    } else if (QString::compare(butVal, "*", Qt::CaseSensitive) == 0) {
        mulTrigger = true;
    } else if (QString::compare(butVal, "+", Qt::CaseSensitive) == 0) {
        addTrigger = true;
    } else {
        subTrigger = true;
    }
    ui->Display->setText("");
}

void MainWindow::EqualButton() {
    double solution = 0.0;
    QString displayVal = ui->Display->text();
    double dblDisplayValue = displayVal.toDouble();
    if (addTrigger || divTrigger || mulTrigger || subTrigger) {
        if (addTrigger)
            solution = calcValue + dblDisplayValue;
        else if (divTrigger)
            solution = calcValue / dblDisplayValue;
        else if (subTrigger)
            solution = calcValue - dblDisplayValue;
        else
            solution = calcValue * dblDisplayValue;
    }
    ui->Display->setText(QString::number(solution));
}


























