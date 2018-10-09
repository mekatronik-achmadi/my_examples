#include <QApplication>
#include "gotocell.h"

int main(int argc, char *argv[]){
    QApplication app(argc,argv);
    frmCell *dialog=new frmCell;
    dialog->show();
    return app.exec();
}
