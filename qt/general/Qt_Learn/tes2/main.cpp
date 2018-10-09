#include <QApplication>
#include "tes2.h"

int main(int argc, char *argv[]){
    QApplication app(argc,argv);
    myDialog *dialog= new myDialog;
    dialog->show();
    return app.exec();
}
