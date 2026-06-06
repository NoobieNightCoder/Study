#include <QFileDialog>
#include <QMessageBox>
#include <QFileInfo>

#include "../AppController/appController.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#define ITEM_OFFSET 2

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentColumn = 1;
    chartViewHandler = ChartViewHandler(ui->chartView);

    connect(ui->loadFileButton, &QPushButton::clicked, this, &MainWindow::onLoadButtonClick);
    connect(ui->calculateButton, &QPushButton::clicked, this, &MainWindow::onCalcualteButtonClick);

    connect(ui->columnInput, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::onColumnEntered);
    connect(ui->regionInput, &QLineEdit::editingFinished, this, &MainWindow::onRegionEntered);
}


void MainWindow::summonMessage(MessageTypes messageType, QString message) {
    QMessageBox msgBox(this);
    msgBox.setText(tr("%1").arg(message));
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);

    if(messageType == MessageTypes::INFO)
        msgBox.setIcon(QMessageBox::Information);
    else if (messageType == MessageTypes::WARNING)
        msgBox.setIcon(QMessageBox::Warning);
    else if (messageType == MessageTypes::CRITICAL)
        msgBox.setIcon(QMessageBox::Critical);
    
    msgBox.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTable(tableData* tableData) {
    int rows = tableData->tableSize;
    ui->tableWidget->setColumnCount(tableData->headerCount);
    ui->tableWidget->setRowCount(rows);

    QStringList headers;
    for (int i = 0; i < tableData->headerCount; i++)
        headers << tableData->headers[i];
    
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    for (int row = 0; row < rows; row++) {
        QTableWidgetItem* newItem1 = new QTableWidgetItem(tr("%1").arg(tableData->table[row].year));
        QTableWidgetItem* newItem2 = new QTableWidgetItem(tr("%1").arg(tableData->table[row].region));

        ui->tableWidget->setItem(row, 0, newItem1);
        ui->tableWidget->setItem(row, 1, newItem2);

        for (int i = 0; i < NUM_DATA_LENGTH; i++) {
            QTableWidgetItem* newItem3 = new QTableWidgetItem(tr("%1").arg(tableData->table[row].numData[i]));
            ui->tableWidget->setItem(row, i + ITEM_OFFSET, newItem3);
        }
    }
}

void MainWindow::onLoadButtonClick() {
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть файл", "", "Table Files (*.csv);");
    QFileInfo fileInfo(fileName);
    bool isLoaded = false;

    if (!fileName.trimmed().isEmpty()) {
        ui->filenameLabel->setText(fileInfo.fileName());
        isLoaded = appController.loadGlobalTable(fileName);
    }

    if (isLoaded) {
        setTable(appController.getGlobalTable());
        summonMessage(MessageTypes::INFO, "Таблица успешно загружана");
        ui->regionInput->setEnabled(true);
        ui->columnInput->setEnabled(true);

        ui->columnInput->setMaximum(COLUMNS);
        ui->columnInput->setValue(1);
        ui->columnInput->setMinimum(1);
    }
}

void MainWindow::onCalcualteButtonClick() {
    CalcResult result;
    result.minValue = 0;
    result.medianValue = 0;
    result.maxValue = 0;

    AppStatus status = appController.calculateStats(&result);

    showStatusError(status);
    updateStatsLabels(&result);
    if (status == OK)
        chartViewHandler.showTable(appController.getTargetTable(), currentColumn);
    else
        chartViewHandler.clear();
}

void MainWindow::onColumnEntered(int value) {
    appController.setTargetColumn(value);
    currentColumn = value;
}

void MainWindow::onRegionEntered() {
    QString region = ui->regionInput->text();
    appController.setTargetRegion(region);

    tableData* table = appController.getTargetTable();
    if (table)
        setTable(table);
}

void MainWindow::updateStatsLabels(const CalcResult* result) {
    ui->minimumLabel->setText(QString::number(result->minValue));
    ui->medianLabel->setText(QString::number(result->medianValue));
    ui->maximumLabel->setText(QString::number(result->maxValue));

}

void MainWindow::showStatusError(AppStatus status) {
    if (status == NO_REGION)
        summonMessage(MessageTypes::WARNING, tr("Не выбран регион"));
    else if (status == INVALID_COLUMN)
        summonMessage(MessageTypes::WARNING, tr("Неверный столбик"));
    else if (status == NO_TABLE)
        summonMessage(MessageTypes::WARNING, tr("Нет таблицы"));
}
