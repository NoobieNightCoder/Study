#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    
    // NUMS AND OPS //
    connect(ui->numButton1, &QPushButton::clicked, this, &MainWindow::onNumNOpClicked);
    connect(ui->numButton2, &QPushButton::clicked, this, &MainWindow::onNumNOpClicked);
    connect(ui->numButton3, &QPushButton::clicked, this, &MainWindow::onNumNOpClicked);
    connect(ui->numButton4, &QPushButton::clicked, this, &MainWindow::onNumNOpClicked);
    connect(ui->numButton5, &QPushButton::clicked, this, &MainWindow::onNumNOpClicked);
    connect(ui->numButton6, &QPushButton::clicked, this, &MainWindow::onNumNOpClicked);
    connect(ui->numButton7, &QPushButton::clicked, this, &MainWindow::onNumNOpClicked);
    connect(ui->numButton8, &QPushButton::clicked, this, &MainWindow::onNumNOpClicked);
    connect(ui->numButton9, &QPushButton::clicked, this, &MainWindow::onNumNOpClicked);
    connect(ui->numButton0, &QPushButton::clicked, this, &MainWindow::onNumNOpClicked);
    connect(ui->numButtonOB, &QPushButton::clicked, this, &MainWindow::onNumNOpClicked);
    connect(ui->numButtonCB, &QPushButton::clicked, this, &MainWindow::onNumNOpClicked);
    connect(ui->numButtonDiv, &QPushButton::clicked, this, &MainWindow::onNumNOpClicked);
    connect(ui->numButtonMul, &QPushButton::clicked, this, &MainWindow::onNumNOpClicked);
    connect(ui->numButtonDot, &QPushButton::clicked, this, &MainWindow::onNumNOpClicked);
    connect(ui->numButtonPlus, &QPushButton::clicked, this, &MainWindow::onNumNOpClicked);
    connect(ui->numButtonMinus, &QPushButton::clicked, this, &MainWindow::onNumNOpClicked);
    
    // FUNCTIONS //
    connect(ui->numButtonTg, &QPushButton::clicked, this, &MainWindow::onFuncClicked);
    connect(ui->numButtonSin, &QPushButton::clicked, this, &MainWindow::onFuncClicked);
    connect(ui->numButtonCos, &QPushButton::clicked, this, &MainWindow::onFuncClicked);
    connect(ui->numButtonCtg, &QPushButton::clicked, this, &MainWindow::onFuncClicked);
    connect(ui->numButtonSqrt, &QPushButton::clicked, this, &MainWindow::onFuncClicked);

    // COMMANDS //
    connect(ui->numButtonC, &QPushButton::clicked, this, &MainWindow::onCommandClicked);
    connect(ui->numButtonMC, &QPushButton::clicked, this, &MainWindow::onCommandClicked);
    connect(ui->numButtonMR, &QPushButton::clicked, this, &MainWindow::onCommandClicked);
    connect(ui->numButtonDel, &QPushButton::clicked, this, &MainWindow::onCommandClicked);
    connect(ui->numButtonCalc, &QPushButton::clicked, this, &MainWindow::onCommandClicked);
    connect(ui->numButtonFunc, &QPushButton::clicked, this, &MainWindow::onCommandClicked);
    connect(ui->numButtonMPlus, &QPushButton::clicked, this, &MainWindow::onCommandClicked);
    connect(ui->numButtonMMinus, &QPushButton::clicked, this, &MainWindow::onCommandClicked);
}

void MainWindow::onNumNOpClicked() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        appController.enterToken(button->text().toStdString());
        ui->label->setText(QString::fromStdString(appController.text()));
    }
}

void MainWindow::onFuncClicked() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        appController.enterFunction(button->text().toStdString());
        ui->label->setText(QString::fromStdString(appController.text()));
    }
}

void MainWindow::onCommandClicked() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        appController.executeCommand(button->text().toStdString());
        ui->label->setText(QString::fromStdString(appController.text()));
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
