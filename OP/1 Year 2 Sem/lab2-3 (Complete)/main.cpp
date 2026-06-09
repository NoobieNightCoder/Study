#include <QApplication>
#include "GUI/mainwindow.h"

// Допов нет

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
