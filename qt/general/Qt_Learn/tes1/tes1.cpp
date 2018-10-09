#include <QApplication>

//#include <QLabel>
//#include <QPushButton>

#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>

int main(int argc, char *argv[]){
  QApplication app(argc,argv);
  
//   QLabel *label= new QLabel("<h2><i>Hello</i> " "<font color=red>Qt!</font></h2>");
//   label->show();
// ==================================================================================  
  
//   QPushButton *button = new QPushButton("Quit");
//   QObject::connect(button,SIGNAL(clicked()),&app,SLOT(quit()));
//   button->show();
// ==================================================================================
  
  QWidget *window = new QWidget;
  window -> setWindowTitle("masukkan kadar");
  QSpinBox *spinbox = new QSpinBox;
  QSlider *slider = new QSlider;
  spinbox -> setRange(0,130);
  slider -> setRange(0,130);
  slider -> setOrientation(Qt::Horizontal);
  QObject::connect(spinbox,SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));
  QObject::connect(slider,SIGNAL(valueChanged(int)),spinbox,SLOT(setValue(int)));
  spinbox->setValue(35);
  QGridLayout *layout = new QGridLayout;
  layout -> addWidget(spinbox);
  layout -> addWidget(slider);
  window -> setLayout(layout);
  window -> show();
  // ==================================================================================


  
  return app.exec();
}
