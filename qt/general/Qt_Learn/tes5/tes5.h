#ifndef TES5_H
#define TES5_H

#include <QMainWindow>

namespace Ui {
class tes5;
}

class tes5 : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit tes5(QWidget *parent = 0);
    ~tes5();
    
private:
    Ui::tes5 *ui;
};

#endif // TES5_H
