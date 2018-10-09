#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

//class QLabel;
//class QLineEdit;
//class QCheckBox;
//class QPushButton;


class myDialog : public QDialog {
    Q_OBJECT

public :
    myDialog(QWidget *parent=0);

signals:
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);

private slots:
    void findClicked();
    void enableFind(const QString &teks);

private:
    QLabel *lblView;
    QLineEdit *lneEdit;
    QCheckBox *chkCase;
    QCheckBox *chkBack;
    QPushButton *btnFind;
    QPushButton *btnClose;
};

#endif
