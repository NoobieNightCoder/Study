#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

/*

    TODO: Сделать хранение InputText и OutputText в AppController

*/

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

    connect(ui->pushButton_convert, &QPushButton::clicked, this, &MainWindow::OnConvertClicked);
    connect(ui->pushButton_swap, &QPushButton::clicked, this, &MainWindow::OnSwapClicked);

    connect(ui->radioInputBin, &QRadioButton::toggled, this, &MainWindow::OnRadioToggled);
    connect(ui->radioInputDec, &QRadioButton::toggled, this, &MainWindow::OnRadioToggled);
    connect(ui->radioInputHex, &QRadioButton::toggled, this, &MainWindow::OnRadioToggled);

    connect(ui->radioOutputBin, &QRadioButton::toggled, this, &MainWindow::OnRadioToggled);
    connect(ui->radioOutputDec, &QRadioButton::toggled, this, &MainWindow::OnRadioToggled);
    connect(ui->radioOutputHex, &QRadioButton::toggled, this, &MainWindow::OnRadioToggled);

    connect(ui->lineEdit_input, &QLineEdit::textChanged, this, &MainWindow::OnEditText);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnRadioToggled(bool toggled) {
    QObject* senderObj = sender();
    if(toggled) {
        if     (senderObj == ui->radioInputBin) Controller.setInputBase(BASE_BIN);
        else if(senderObj == ui->radioInputDec) Controller.setInputBase(BASE_DEC);
        else if(senderObj == ui->radioInputHex) Controller.setInputBase(BASE_HEX);

        else if(senderObj == ui->radioOutputBin) Controller.setOutputBase(BASE_BIN);
        else if(senderObj == ui->radioOutputDec) Controller.setOutputBase(BASE_DEC);
        else if(senderObj == ui->radioOutputHex) Controller.setOutputBase(BASE_HEX);
    }
}

void MainWindow::OnEditText(const QString& text) {
    Controller.setInputText(text);
}

void MainWindow::SetInputBase(Base BaseValue) {
    ui->radioInputHex->setChecked(BaseValue == BASE_HEX);
    ui->radioInputDec->setChecked(BaseValue == BASE_DEC);
    ui->radioInputBin->setChecked(BaseValue == BASE_BIN);
}

void MainWindow::SetOutputBase(Base BaseValue) {
    ui->radioOutputHex->setChecked(BaseValue == BASE_HEX);
    ui->radioOutputDec->setChecked(BaseValue == BASE_DEC);
    ui->radioOutputBin->setChecked(BaseValue == BASE_BIN);
}

void MainWindow::ShowError(const QString& ErrorMessage) {
    ui->labelError->setText(ErrorMessage);
}

void MainWindow::ClearError() {
    ui->labelError->clear();
}

void MainWindow::OnConvertClicked() {
    ClearError();

    auto Response = Controller.Convert();

    if (!Response.ErrorText.isEmpty()) {
        ShowError(Response.ErrorText);
        ui->lineEdit_output->clear();
    } else
        ui->lineEdit_output->setText(Response.ResultText);
}

void MainWindow::OnSwapClicked() {
    ClearError();

    QString ErrorText;

    bool Success = Controller.SwapValues(ErrorText);

    Base InputBase = Controller.getInputBase();
    Base OutputBase = Controller.getOutputBase();
    QString InputText = Controller.getInputText();
    QString OutputText = Controller.getOutputText();

    if (!Success)
        ShowError(ErrorText);
    else {
        ui->lineEdit_input->setText(InputText);
        ui->lineEdit_output->setText(OutputText);

        SetInputBase(InputBase);
        SetOutputBase(OutputBase);
    }
}
