#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

typedef enum {
    HEX = 1,
    DEC = 2,
    BIN = 3
} RadioChoice;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->ConvertButton, &QPushButton::clicked, this, &MainWindow::onConvertButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onConvertButtonClicked()
{
    int RadioState = 0;
    if(ui->HEXToggleTo->isChecked()) RadioState = HEX;
    if(ui->DECToggleTo->isChecked()) RadioState = DEC;
    if(ui->BINToggleTo->isChecked()) RadioState = BIN;


    // QString aboba = ui->NumInput->text();
    QString newText = controller.handleButtonClick(RadioState);
    ui->OutputLabel->setText(newText);
}