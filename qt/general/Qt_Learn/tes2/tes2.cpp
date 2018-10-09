#include <QtGui>
#include "tes2.h"

myDialog::myDialog(QWidget *parent)
    : QDialog(parent)
{
    lblView = new QLabel(tr("Find &What:"));

    lneEdit = new QLineEdit;

    lblView ->setBuddy(lneEdit);

    chkCase = new QCheckBox(tr("Match &case"));

    chkBack = new QCheckBox(tr("Search &backward"));

    btnFind = new QPushButton(tr("&Find"));
    btnFind->setDefault(true);
    btnFind->setEnabled(false);

    btnClose=new QPushButton(tr("&Close"));

    connect(lneEdit,SIGNAL(textChanged(const QString &)),this,SLOT(enableFind(const QString &)));
    connect(btnFind,SIGNAL(clicked()),this,SLOT(findClicked()));
    connect(btnClose,SIGNAL(clicked()),this,SLOT(close()));

    QHBoxLayout *topLeft=new QHBoxLayout;
    topLeft->addWidget(lblView);
    topLeft->addWidget(lneEdit);

    QVBoxLayout *centreLeft = new QVBoxLayout;
    centreLeft->addLayout(topLeft);
    centreLeft->addWidget(chkCase);
    centreLeft->addWidget(chkBack);

    QVBoxLayout *centreRight = new QVBoxLayout;
    centreRight ->addWidget(btnFind);
    centreRight->addWidget(btnClose);
    centreRight->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout ->addLayout(centreLeft);
    mainLayout->addLayout(centreRight);

    setLayout(mainLayout);
    setWindowTitle(tr("Find"));
    setFixedHeight(sizeHint().height());
}

void myDialog::findClicked(){
    QStr teks= lneEdit->text();
    Qt::CaseSensitivity cs= chkCase->isChecked()?Qt::CaseSensitive
                                                                                : Qt::CaseInsensitive;
    if(chkBack->isChecked()){
        emit findPrevious(teks,cs);
    }else
        emit findNext(teks,cs);
}

void myDialog::enableFind(const QString &teks){
    btnFind->setEnabled(!teks.isEmpty());
}
