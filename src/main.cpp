#include "GUI/MainWindow.h"
#include <QtWidgets/QApplication>

#include "GUI/StyleConfigurator.h"

int main(int argc, char *argv[])
{
    StyleConfigurator::SetDarkStyle();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
