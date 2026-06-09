#include <QApplication>
#include "GUI/mainwindow.h"

// Допы: "Кнопка перестановки систем счислений и значений"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
