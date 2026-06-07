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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelTitle;
    QHBoxLayout *inputRow;
    QVBoxLayout *inputColumn;
    QLabel *labelInput;
    QLineEdit *lineEdit_input;
    QGroupBox *groupBox_inputBase;
    QHBoxLayout *layout_inputRadios;
    QRadioButton *radioInputHex;
    QRadioButton *radioInputDec;
    QRadioButton *radioInputBin;
    QHBoxLayout *outputRow;
    QVBoxLayout *outputColumn;
    QLabel *labelOutput;
    QLineEdit *lineEdit_output;
    QGroupBox *groupBox_outputBase;
    QHBoxLayout *layout_outputRadios;
    QRadioButton *radioOutputHex;
    QRadioButton *radioOutputDec;
    QRadioButton *radioOutputBin;
    QHBoxLayout *actionRow;
    QSpacerItem *horizontalSpacer_left;
    QFrame *actionButtonsFrame;
    QHBoxLayout *layout_actionButtons;
    QPushButton *pushButton_swap;
    QPushButton *pushButton_convert;
    QSpacerItem *horizontalSpacer_right;
    QLabel *labelError;
    QSpacerItem *verticalSpacer_bottom;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(520, 440);
        MainWindow->setMinimumSize(QSize(520, 440));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMinimumSize(QSize(480, 320));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        labelTitle = new QLabel(centralwidget);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelTitle->setMargin(8);

        verticalLayout->addWidget(labelTitle);

        inputRow = new QHBoxLayout();
        inputRow->setObjectName("inputRow");
        inputColumn = new QVBoxLayout();
        inputColumn->setObjectName("inputColumn");
        labelInput = new QLabel(centralwidget);
        labelInput->setObjectName("labelInput");

        inputColumn->addWidget(labelInput);

        lineEdit_input = new QLineEdit(centralwidget);
        lineEdit_input->setObjectName("lineEdit_input");

        inputColumn->addWidget(lineEdit_input);

        groupBox_inputBase = new QGroupBox(centralwidget);
        groupBox_inputBase->setObjectName("groupBox_inputBase");
        layout_inputRadios = new QHBoxLayout(groupBox_inputBase);
        layout_inputRadios->setObjectName("layout_inputRadios");
        radioInputHex = new QRadioButton(groupBox_inputBase);
        radioInputHex->setObjectName("radioInputHex");
        radioInputHex->setChecked(false);

        layout_inputRadios->addWidget(radioInputHex);

        radioInputDec = new QRadioButton(groupBox_inputBase);
        radioInputDec->setObjectName("radioInputDec");
        radioInputDec->setChecked(true);

        layout_inputRadios->addWidget(radioInputDec);

        radioInputBin = new QRadioButton(groupBox_inputBase);
        radioInputBin->setObjectName("radioInputBin");

        layout_inputRadios->addWidget(radioInputBin);


        inputColumn->addWidget(groupBox_inputBase);


        inputRow->addLayout(inputColumn);


        verticalLayout->addLayout(inputRow);

        outputRow = new QHBoxLayout();
        outputRow->setObjectName("outputRow");
        outputColumn = new QVBoxLayout();
        outputColumn->setObjectName("outputColumn");
        labelOutput = new QLabel(centralwidget);
        labelOutput->setObjectName("labelOutput");

        outputColumn->addWidget(labelOutput);

        lineEdit_output = new QLineEdit(centralwidget);
        lineEdit_output->setObjectName("lineEdit_output");
        lineEdit_output->setReadOnly(true);

        outputColumn->addWidget(lineEdit_output);

        groupBox_outputBase = new QGroupBox(centralwidget);
        groupBox_outputBase->setObjectName("groupBox_outputBase");
        layout_outputRadios = new QHBoxLayout(groupBox_outputBase);
        layout_outputRadios->setObjectName("layout_outputRadios");
        radioOutputHex = new QRadioButton(groupBox_outputBase);
        radioOutputHex->setObjectName("radioOutputHex");

        layout_outputRadios->addWidget(radioOutputHex);

        radioOutputDec = new QRadioButton(groupBox_outputBase);
        radioOutputDec->setObjectName("radioOutputDec");
        radioOutputDec->setChecked(true);

        layout_outputRadios->addWidget(radioOutputDec);

        radioOutputBin = new QRadioButton(groupBox_outputBase);
        radioOutputBin->setObjectName("radioOutputBin");

        layout_outputRadios->addWidget(radioOutputBin);


        outputColumn->addWidget(groupBox_outputBase);


        outputRow->addLayout(outputColumn);


        verticalLayout->addLayout(outputRow);

        actionRow = new QHBoxLayout();
        actionRow->setObjectName("actionRow");
        horizontalSpacer_left = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        actionRow->addItem(horizontalSpacer_left);

        actionButtonsFrame = new QFrame(centralwidget);
        actionButtonsFrame->setObjectName("actionButtonsFrame");
        layout_actionButtons = new QHBoxLayout(actionButtonsFrame);
        layout_actionButtons->setObjectName("layout_actionButtons");
        pushButton_swap = new QPushButton(actionButtonsFrame);
        pushButton_swap->setObjectName("pushButton_swap");
        pushButton_swap->setMinimumSize(QSize(64, 36));

        layout_actionButtons->addWidget(pushButton_swap);

        pushButton_convert = new QPushButton(actionButtonsFrame);
        pushButton_convert->setObjectName("pushButton_convert");
        pushButton_convert->setMinimumSize(QSize(160, 36));

        layout_actionButtons->addWidget(pushButton_convert);


        actionRow->addWidget(actionButtonsFrame);

        horizontalSpacer_right = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        actionRow->addItem(horizontalSpacer_right);


        verticalLayout->addLayout(actionRow);

        labelError = new QLabel(centralwidget);
        labelError->setObjectName("labelError");
        labelError->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(labelError);

        verticalSpacer_bottom = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_bottom);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 520, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\275\320\262\320\265\321\200\321\202\320\265\321\200 \321\201\320\270\321\201\321\202\320\265\320\274 \321\201\321\207\320\270\321\201\320\273\320\265\320\275\320\270\321\217", nullptr));
        labelTitle->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\275\320\262\320\265\321\200\321\202\320\265\321\200 \321\201\320\270\321\201\321\202\320\265\320\274 \321\201\321\207\320\270\321\201\320\273\320\265\320\275\320\270\321\217", nullptr));
        labelInput->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264 (\321\207\320\270\321\201\320\273\320\276):", nullptr));
        lineEdit_input->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\207\320\270\321\201\320\273\320\276 (\320\275\320\260\320\277\321\200\320\270\320\274\320\265\321\200: FF, 255, 11111111)", nullptr));
        groupBox_inputBase->setTitle(QCoreApplication::translate("MainWindow", "\320\230\321\201\321\205\320\276\320\264\320\275\320\260\321\217 \321\201\320\270\321\201\321\202\320\265\320\274\320\260", nullptr));
        radioInputHex->setText(QCoreApplication::translate("MainWindow", "HEX", nullptr));
        radioInputDec->setText(QCoreApplication::translate("MainWindow", "DEC", nullptr));
        radioInputBin->setText(QCoreApplication::translate("MainWindow", "BIN", nullptr));
        labelOutput->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202:", nullptr));
        lineEdit_output->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\227\320\264\320\265\321\201\321\214 \320\261\321\203\320\264\320\265\321\202 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\321\221\320\275 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        groupBox_outputBase->setTitle(QCoreApplication::translate("MainWindow", "\320\246\320\265\320\273\320\265\320\262\320\260\321\217 \321\201\320\270\321\201\321\202\320\265\320\274\320\260", nullptr));
        radioOutputHex->setText(QCoreApplication::translate("MainWindow", "HEX", nullptr));
        radioOutputDec->setText(QCoreApplication::translate("MainWindow", "DEC", nullptr));
        radioOutputBin->setText(QCoreApplication::translate("MainWindow", "BIN", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_swap->setToolTip(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\274\320\265\320\275\321\217\321\202\321\214 \321\201\320\270\321\201\321\202\320\265\320\274\321\213 \320\270 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217 \320\274\320\265\321\201\321\202\320\260\320\274\320\270", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_swap->setText(QCoreApplication::translate("MainWindow", "<-->", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_convert->setToolTip(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\266\320\274\320\270\321\202\320\265 \320\264\320\273\321\217 \320\275\320\260\321\207\320\260\320\273\320\260 \320\272\320\276\320\275\320\262\320\265\321\200\321\201\320\270\320\270", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_convert->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\275\320\262\320\265\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        labelError->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #cc0000; font-weight: 600;", nullptr));
        labelError->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
