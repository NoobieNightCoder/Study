#pragma once

#include <QMainWindow>
#include "../AppController/appController.h"
#include "chartViewHandler.h"

enum class MessageTypes {
    INFO = 1,
    WARNING = 2,
    CRITICAL = 3
};

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onLoadButtonClick();
    void onCalcualteButtonClick();
    void onRegionEntered();
    void onColumnEntered(int value);

private:
    void summonMessage(MessageTypes typeMessage, QString message);
    void setTable(tableData* tableData);
    void updateStatsLabels(const CalcResult* result);
    void showStatusError(AppStatus status);

    Ui::MainWindow *ui;
    AppController appController;
    ChartViewHandler chartViewHandler;
    int currentColumn;
};
