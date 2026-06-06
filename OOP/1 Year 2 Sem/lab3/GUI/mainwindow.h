#pragma once

#include "../AppController/AppController.h"
#include <QMainWindow>

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
    void onNumNOpClicked();
    void onFuncClicked();
    void onCommandClicked();

private:
    Ui::MainWindow *ui;
    AppController appController;
};
