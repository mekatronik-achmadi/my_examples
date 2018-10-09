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


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),port(0),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->txtData->installEventFilter(this);

    connect(ui->actionAbout,SIGNAL(triggered()),this,SLOT(app_about()));
    connect(ui->actionQuit,SIGNAL(triggered()),this,SLOT(app_quit()));

    connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(startComm()));
    connect(ui->actionClose,SIGNAL(triggered()),this,SLOT(stopComm()));
    connect(ui->actionClear,SIGNAL(triggered()),this,SLOT(txt_clear()));

    connect(&timer,SIGNAL(timeout()),this,SLOT(onComm()));
    timer.start(100);

    license();
}

MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::eventFilter(QObject *obj, QEvent *event){
    if(event->type()== QEvent::KeyPress){
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);

        if(port){

            QString s = keyEvent->text();

            if(s.length()){
                char ch= s.at(0).toAscii();
                port->putChar(ch);
                QString str(ch);
                ui->txtData->insertPlainText(str);
            }
        }
        return true;
    }
    else{
        return QObject::eventFilter(obj,event);
    }
}



void MainWindow::startComm(void){
    if(port){
        delete port;
        port=NULL;
    }

    devicePort = ui->txtPort->text();

    QString device;
    device = QString("/dev/");
    device += devicePort;

    baudRate = BAUD9600;

    port = new QextSerialPort(device,QextSerialPort::Polling);

    port->setBaudRate(baudRate);
    port->setDataBits(DATA_8);
    port->setParity(PAR_NONE);
    port->setStopBits(STOP_1);
    port->setFlowControl(FLOW_OFF);

    port->setTimeout(100);

    if(!port->open(QIODevice::ReadWrite)){
        delete port;
        port=NULL;

        QString s("Cannot open device at ");
        s+= device;
        QMessageBox::critical(this,"Error",s);
    }
    else{
        QString s("Successfull open device at ");
        s+= device;
        QMessageBox::information(this,"Success",s);
    }
}

void MainWindow::stopComm(void){
    if(port){
        delete port;
        port=NULL;
    }
}

void MainWindow::app_quit(void){
    QApplication::quit();
}

void MainWindow::app_about(void){
    QMessageBox::aboutQt(this,"This software using Qt4");
}

void MainWindow::license(void){
    QString s("");

              s+="QSerialTerminal. A simple serial comm terminal using Qt and QextSerialPort libraries based on famous QST.\n";
              s+="\n";
              s+="Copyright (C) 2013 by Achmadi\n";
              s+="\n";
              s+="This program is free software; you can redistribute it and/or modify\n";
              s+="it under the terms of the GNU General Public License as published\n";
              s+="by the Free Software Foundation; either version 2 of the License, or\n";
              s+="(at your option) any later version.\n";
              s+="\n";
              s+="This program is distributed in the hope that it will be useful,\n";
              s+="but WITHOUT ANY WARRANTY;without even the implied warranty of\n";
              s+="MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n";
              s+="See the GNU General Public License for more details.\n";
              s+="\n";
              s+="You should have received a copy of the GNU General Public License\n";
              s+="along with this program;if not, see <http://www.gnu.org/licenses/>.\n";
              s+="\n";
              s+="Contact me at facebook in mekatronik.achmadi@gmail.com\n";

    QMessageBox::information(this,"Please Read The License",s);
}

void MainWindow::txt_clear(void){
    ui->txtData->clear();
}

void MainWindow::onComm(void){
    if(!port){return;}

    //port->putChar('a');

    QString s = port->readAll();

    ui->txtData->insertPlainText(s);
    ui->txtBuffer->setText(s);
}
