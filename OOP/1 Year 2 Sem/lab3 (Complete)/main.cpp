#include <QApplication>
#include "GUI/mainwindow.h"

// Допы: "Работа с памятью", "Тригонометрические функции"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}