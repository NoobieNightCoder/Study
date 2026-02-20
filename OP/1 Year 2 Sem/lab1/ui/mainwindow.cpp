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
    int radioStateFrom = 0, radioStateTo = 0;
    if(ui->HEXToggleTo->isChecked())      radioStateTo = HEX;
    else if(ui->DECToggleTo->isChecked()) radioStateTo = DEC;
    else if(ui->BINToggleTo->isChecked()) radioStateTo = BIN;

    if(ui->HEXToggleFrom->isChecked())      radioStateFrom = HEX;
    else if(ui->DECToggleFrom->isChecked()) radioStateFrom = DEC;
    else if(ui->BINToggleFrom->isChecked()) radioStateFrom = BIN;


    QString inputText = ui->NumInput->text();
    QString newText = controller.handleButtonClick(inputText, radioStateFrom, radioStateTo);
    ui->OutputLabel->setText(newText);
}