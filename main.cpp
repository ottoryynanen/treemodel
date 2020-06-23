#include "treewindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TreeWindow w;
    w.show();
    return a.exec();
}
