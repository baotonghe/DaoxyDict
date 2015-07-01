#include "DaoxyDictMainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DaoxyDictMainWindow w;
    w.show();

    return a.exec();
}
