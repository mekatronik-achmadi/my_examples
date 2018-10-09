#ifndef TGS1_H
#define TGS1_H

#include <QMainWindow>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

namespace Ui {
class tgs1;
}

class tgs1 : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit tgs1(QWidget *parent = 0);
    ~tgs1();
    
private:
    Ui::tgs1 *ui;
    cv::Mat img_obj;
};

#endif // TGS1_H
