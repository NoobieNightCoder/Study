#pragma once

#include <QMainWindow>
#include "app_controller.h"

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
    void OnConvertClicked();
    void OnSwapClicked();

private:
    Ui::MainWindow *ui;
    AppController Controller;

    Base GetInputBase() const;
    Base GetOutputBase() const;
    void SetInputBase(Base BaseValue);
    void SetOutputBase(Base BaseValue);

    void ShowError(const QString& ErrorMessage);
    void ClearError();
};
