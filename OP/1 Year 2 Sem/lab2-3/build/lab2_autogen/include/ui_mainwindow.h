/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *mainVerticalLayout;
    QHBoxLayout *topHorizontalLayout;
    QPushButton *loadFileButton;
    QLabel *filenameLabel;
    QHBoxLayout *inputHorizontalLayout;
    QLabel *regionLabel;
    QLineEdit *regionInput;
    QLabel *numColumnLabel;
    QSpinBox *columnInput;
    QPushButton *calculateButton;
    QTableWidget *tableWidget;
    QGraphicsView *chartView;
    QGroupBox *resultsGroupBox;
    QGridLayout *gridLayout;
    QLabel *NEminimumLabel;
    QLabel *NEmaximumLabel;
    QLabel *minimumLabel;
    QLabel *NEmedianLabel;
    QLabel *medianLabel;
    QLabel *maximumLabel;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(980, 720);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        mainVerticalLayout = new QVBoxLayout(centralwidget);
        mainVerticalLayout->setObjectName("mainVerticalLayout");
        topHorizontalLayout = new QHBoxLayout();
        topHorizontalLayout->setObjectName("topHorizontalLayout");
        loadFileButton = new QPushButton(centralwidget);
        loadFileButton->setObjectName("loadFileButton");

        topHorizontalLayout->addWidget(loadFileButton);

        filenameLabel = new QLabel(centralwidget);
        filenameLabel->setObjectName("filenameLabel");

        topHorizontalLayout->addWidget(filenameLabel);


        mainVerticalLayout->addLayout(topHorizontalLayout);

        inputHorizontalLayout = new QHBoxLayout();
        inputHorizontalLayout->setObjectName("inputHorizontalLayout");
        regionLabel = new QLabel(centralwidget);
        regionLabel->setObjectName("regionLabel");

        inputHorizontalLayout->addWidget(regionLabel);

        regionInput = new QLineEdit(centralwidget);
        regionInput->setObjectName("regionInput");

        inputHorizontalLayout->addWidget(regionInput);

        numColumnLabel = new QLabel(centralwidget);
        numColumnLabel->setObjectName("numColumnLabel");

        inputHorizontalLayout->addWidget(numColumnLabel);

        columnInput = new QSpinBox(centralwidget);
        columnInput->setObjectName("columnInput");
        columnInput->setMinimum(0);
        columnInput->setMaximum(999);
        columnInput->setValue(0);

        inputHorizontalLayout->addWidget(columnInput);

        calculateButton = new QPushButton(centralwidget);
        calculateButton->setObjectName("calculateButton");

        inputHorizontalLayout->addWidget(calculateButton);


        mainVerticalLayout->addLayout(inputHorizontalLayout);

        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");

        mainVerticalLayout->addWidget(tableWidget);

        chartView = new QGraphicsView(centralwidget);
        chartView->setObjectName("chartView");

        mainVerticalLayout->addWidget(chartView);

        resultsGroupBox = new QGroupBox(centralwidget);
        resultsGroupBox->setObjectName("resultsGroupBox");
        gridLayout = new QGridLayout(resultsGroupBox);
        gridLayout->setObjectName("gridLayout");
        NEminimumLabel = new QLabel(resultsGroupBox);
        NEminimumLabel->setObjectName("NEminimumLabel");

        gridLayout->addWidget(NEminimumLabel, 0, 0, 1, 1);

        NEmaximumLabel = new QLabel(resultsGroupBox);
        NEmaximumLabel->setObjectName("NEmaximumLabel");

        gridLayout->addWidget(NEmaximumLabel, 3, 0, 1, 1);

        minimumLabel = new QLabel(resultsGroupBox);
        minimumLabel->setObjectName("minimumLabel");

        gridLayout->addWidget(minimumLabel, 0, 1, 1, 1);

        NEmedianLabel = new QLabel(resultsGroupBox);
        NEmedianLabel->setObjectName("NEmedianLabel");

        gridLayout->addWidget(NEmedianLabel, 4, 0, 1, 1);

        medianLabel = new QLabel(resultsGroupBox);
        medianLabel->setObjectName("medianLabel");

        gridLayout->addWidget(medianLabel, 4, 1, 1, 1);

        maximumLabel = new QLabel(resultsGroupBox);
        maximumLabel->setObjectName("maximumLabel");

        gridLayout->addWidget(maximumLabel, 3, 1, 1, 1);


        mainVerticalLayout->addWidget(resultsGroupBox);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "CSV Metrics Calculator", nullptr));
        loadFileButton->setText(QCoreApplication::translate("MainWindow", "Load data", nullptr));
        filenameLabel->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273 \320\275\320\265 \320\262\321\213\320\261\321\200\320\260\320\275", nullptr));
        regionLabel->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\263\320\270\320\276\320\275:", nullptr));
        regionInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\200\320\265\320\263\320\270\320\276\320\275", nullptr));
        numColumnLabel->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \321\201\321\202\320\276\320\273\320\261\321\206\320\260:", nullptr));
        calculateButton->setText(QCoreApplication::translate("MainWindow", "Calculate metrics", nullptr));
        resultsGroupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213", nullptr));
        NEminimumLabel->setText(QCoreApplication::translate("MainWindow", "\320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265:", nullptr));
        NEmaximumLabel->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265:", nullptr));
        minimumLabel->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        NEmedianLabel->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\264\320\270\320\260\320\275\320\260:", nullptr));
        medianLabel->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        maximumLabel->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
