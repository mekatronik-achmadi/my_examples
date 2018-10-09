#ifndef GOTOCELL_H
#define GOTOCELL_H

#include <QDialog>
#include "ui_frmCell.h"

class frmCell : public QDialog, public Ui::frmCell{
  Q_OBJECT
  
public:
  frmCell(QWidget *parent=0);
private slots:
  void on_lneCell_textChanged();
};

#endif
