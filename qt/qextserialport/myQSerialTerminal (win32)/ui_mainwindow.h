/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Aug 12 15:36:22 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionQuit;
    QAction *actionOpen;
    QAction *actionClose;
    QAction *actionClear;
    QWidget *centralWidget;
    QLineEdit *txtPort;
    QLabel *label;
    QLabel *label_2;
    QPlainTextEdit *txtData;
    QLineEdit *txtBuffer;
    QMenuBar *menuBar;
    QMenu *menuFILE;
    QMenu *menuCOMM;
    QMenu *menuConnect;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(281, 425);
        QIcon icon;
        icon.addFile(QString::fromUtf8("KDE_Logo_compress.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QString::fromUtf8("actionClear"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        txtPort = new QLineEdit(centralWidget);
        txtPort->setObjectName(QString::fromUtf8("txtPort"));
        txtPort->setGeometry(QRect(150, 10, 113, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 81, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 50, 161, 20));
        txtData = new QPlainTextEdit(centralWidget);
        txtData->setObjectName(QString::fromUtf8("txtData"));
        txtData->setGeometry(QRect(20, 80, 241, 221));
        txtBuffer = new QLineEdit(centralWidget);
        txtBuffer->setObjectName(QString::fromUtf8("txtBuffer"));
        txtBuffer->setGeometry(QRect(20, 320, 241, 23));
        txtBuffer->setReadOnly(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 281, 20));
        menuFILE = new QMenu(menuBar);
        menuFILE->setObjectName(QString::fromUtf8("menuFILE"));
        menuCOMM = new QMenu(menuBar);
        menuCOMM->setObjectName(QString::fromUtf8("menuCOMM"));
        menuConnect = new QMenu(menuCOMM);
        menuConnect->setObjectName(QString::fromUtf8("menuConnect"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFILE->menuAction());
        menuBar->addAction(menuCOMM->menuAction());
        menuFILE->addAction(actionClear);
        menuFILE->addAction(actionAbout);
        menuFILE->addSeparator();
        menuFILE->addAction(actionQuit);
        menuCOMM->addAction(menuConnect->menuAction());
        menuConnect->addAction(actionOpen);
        menuConnect->addAction(actionClose);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionClose);
        mainToolBar->addAction(actionClear);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAbout);
        mainToolBar->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Mamad's Terminal", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
        actionClear->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        txtPort->setText(QApplication::translate("MainWindow", "COM1", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Device Port", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Parameters : 9600-8-n-1", 0, QApplication::UnicodeUTF8));
        menuFILE->setTitle(QApplication::translate("MainWindow", "FILE", 0, QApplication::UnicodeUTF8));
        menuCOMM->setTitle(QApplication::translate("MainWindow", "COMM", 0, QApplication::UnicodeUTF8));
        menuConnect->setTitle(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
