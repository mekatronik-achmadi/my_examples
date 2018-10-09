#include "tes4.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tes4 w;
    w.show();

    return a.exec();
}
