#include "tgs1.h"
#include "ui_tgs1.h"

tgs1::tgs1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tgs1)
{
    ui->setupUi(this);

    img_obj= cv::imread("achmadi.jpg");

//    cv::Mat img_pic= img_obj(cv::Rect(10,10,300,300));
    cv::namedWindow("fotoku");
    cv::imshow("fotoku",img_obj);
    cv::waitKey();
}

tgs1::~tgs1()
{
    delete ui;
}
