#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->elevatorCall1Button, &QPushButton::clicked, this, &MainWindow::floorButtonClicked);
    connect(ui->elevatorCall2Button, &QPushButton::clicked, this, &MainWindow::floorButtonClicked);
    connect(ui->elevatorCall3Button, &QPushButton::clicked, this, &MainWindow::floorButtonClicked);
    connect(ui->elevatorCall4Button, &QPushButton::clicked, this, &MainWindow::floorButtonClicked);
    connect(ui->elevatorCall5Button, &QPushButton::clicked, this, &MainWindow::floorButtonClicked);

    connect(ui->homeCall1Button, &QPushButton::clicked, this, &MainWindow::floorButtonClicked);
    connect(ui->homeCall2Button, &QPushButton::clicked, this, &MainWindow::floorButtonClicked);
    connect(ui->homeCall3Button, &QPushButton::clicked, this, &MainWindow::floorButtonClicked);
    connect(ui->homeCall4Button, &QPushButton::clicked, this, &MainWindow::floorButtonClicked);
    connect(ui->homeCall5Button, &QPushButton::clicked, this, &MainWindow::floorButtonClicked);


   
}

void MainWindow::floorButtonClicked() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QString text = button->text();
        ui->currentFloorValueLabel->setText(text);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
