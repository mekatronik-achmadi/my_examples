#include <QtGui>
#include "gotocell.h"

frmCell::frmCell(QWidget *parent)
  :QDialog(parent)
  
  {
    setupUi(this);
    QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
    lneCell->setValidator(new QRegExpValidator(regExp, this));
    connect(btnOk, SIGNAL(clicked()), this, SLOT(accept()));
    connect(btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
  }
  
  
void frmCell::on_lneCell_textChanged()
{
  btnOk->setEnabled(lneCell->hasAcceptableInput());
}
