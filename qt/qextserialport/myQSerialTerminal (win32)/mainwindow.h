/*
 *
 *  QSerialTerminal. A simple serial comm terminal using Qt and QextSerialPort libraries

    Copyright (C) 2013 by Achmadi

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

    Contact me at facebook in mekatronik.achmadi@gmail.com
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include "SerialPortLibs/qextserialport.h"
#include "SerialPortLibs/qextserialenumerator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    QextSerialPort *port;
    Ui::MainWindow *ui;

    bool eventFilter(QObject *obj, QEvent *event);
    BaudRateType baudRate;
    QString devicePort;

    QTimer timer;

private slots:

    void startComm(void);
    void stopComm(void);
    void onComm(void);

    void app_quit(void);
    void app_about(void);
    void license(void);
    void txt_clear(void);
};

#endif // MAINWINDOW_H
