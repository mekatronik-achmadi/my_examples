#-------------------------------------------------
#
# Project created by QtCreator 2013-08-05T22:21:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QSerialTerminal
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    SerialPortLibs/qextserialport.cpp \
    SerialPortLibs/qextserialenumerator.cpp \
    SerialPortLibs/qextserialbase.cpp \
    SerialPortLibs/win_qextserialport.cpp

HEADERS  += mainwindow.h \
    SerialPortLibs/qextserialport.h \
    SerialPortLibs/qextserialenumerator.h \
    SerialPortLibs/qextserialbase.h \
    SerialPortLibs/win_qextserialport.h

FORMS    += mainwindow.ui

DEFINES += _TTY_WIN_
