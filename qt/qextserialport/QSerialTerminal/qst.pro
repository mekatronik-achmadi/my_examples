# -------------------------------------------------
# Project created by QtCreator 2010-03-28T13:06:00
# -------------------------------------------------

TARGET = qst
TEMPLATE = app
QT       += core gui widgets

SOURCES += main.cpp \
    mainwindow.cpp \
    led.cpp \
    qextserialport.cpp \
    qextserialbase.cpp \
    qextserialenumerator.cpp \
    posix_qextserialport.cpp

HEADERS += mainwindow.h \
    led.h \
    qextserialport.h \
    qextserialbase.h \
    qextserialenumerator.h \
    posix_qextserialport.h

FORMS += mainwindow.ui \
    config.ui \
    about.ui
    
DEFINES += _TTY_POSIX_
RESOURCES += qst.qrc
