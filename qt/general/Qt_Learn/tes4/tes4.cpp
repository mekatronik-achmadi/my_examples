#include "tes4.h"
#include "ui_tes4.h"

tes4::tes4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tes4)
{
    ui->setupUi(this);
    ui->boxSecondary->setVisible(false);
    ui->boxTertiary->setVisible(false);
    connect(ui->btnAdv,SIGNAL(clicked()),this,SLOT(idealSize()));
}

tes4::~tes4()
{
    delete ui;
}

void tes4::idealSize(){
    //this->setFixedSize(sizeHint().width(),sizeHint().height());
}
