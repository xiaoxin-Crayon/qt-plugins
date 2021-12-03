#include "VSPlugins.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VSPlugins w;
    w.show();
    return a.exec();
}
