#include "tes5.h"
#include "ui_tes5.h"

tes5::tes5(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tes5)
{
    ui->setupUi(this);
}

tes5::~tes5()
{
    delete ui;
}
