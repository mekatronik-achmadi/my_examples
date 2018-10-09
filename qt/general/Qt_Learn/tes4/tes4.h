#ifndef TES4_H
#define TES4_H

#include <QWidget>

namespace Ui {
class tes4;
}

class tes4 : public QWidget
{
    Q_OBJECT
    
public:
    explicit tes4(QWidget *parent = 0);
    ~tes4();
    
private:
    Ui::tes4 *ui;

private slots:
    void idealSize();
};

#endif // TES4_H
