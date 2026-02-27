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

    connect(ui->pushButton_convert, &QPushButton::clicked, this, &MainWindow::OnConvertClicked);
    connect(ui->pushButton_swap, &QPushButton::clicked, this, &MainWindow::OnSwapClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

Base MainWindow::GetInputBase() const {
    Base InputBase = BASE_DEC;

    if (ui->radioInputHex->isChecked()) {
        InputBase = BASE_HEX;
    } else if (ui->radioInputBin->isChecked()) {
        InputBase = BASE_BIN;
    }

    return InputBase;
}

Base MainWindow::GetOutputBase() const {
    Base OutputBase = BASE_DEC;

    if (ui->radioOutputHex->isChecked()) {
        OutputBase = BASE_HEX;
    } else if (ui->radioOutputBin->isChecked()) {
        OutputBase = BASE_BIN;
    }

    return OutputBase;
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

    QString InputText = ui->lineEdit_input->text();
    Base InputBase = GetInputBase();
    Base OutputBase = GetOutputBase();

    auto Response = Controller.Convert(InputText, InputBase, OutputBase);

    if (!Response.ErrorText.isEmpty()) {
        ShowError(Response.ErrorText);
        ui->lineEdit_output->clear();
    } else {
        ui->lineEdit_output->setText(Response.ResultText);
    }
}

void MainWindow::OnSwapClicked() {
    ClearError();

    QString InputText = ui->lineEdit_input->text();
    QString OutputText = ui->lineEdit_output->text();
    Base InputBase = GetInputBase();
    Base OutputBase = GetOutputBase();

    QString ErrorText;

    bool Success =
        Controller.SwapValues(InputText, InputBase, OutputText, OutputBase, ErrorText);

    if (!Success) {
        ShowError(ErrorText);
    } else {
        ui->lineEdit_input->setText(InputText);
        ui->lineEdit_output->setText(OutputText);

        SetInputBase(InputBase);
        SetOutputBase(OutputBase);
    }
}
