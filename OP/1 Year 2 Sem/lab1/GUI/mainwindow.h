#pragma once

#include <QMainWindow>
#include "appController.h"

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
    void OnRadioToggled(bool);
    void OnEditText(const QString&);

private:
    Ui::MainWindow *ui;
    AppController Controller;

    void SetInputBase(Base BaseValue);
    void SetOutputBase(Base BaseValue);

    void ShowError(const QString& ErrorMessage);
    void ClearError();
};
