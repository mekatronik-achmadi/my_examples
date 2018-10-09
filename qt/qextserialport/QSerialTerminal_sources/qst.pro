# -------------------------------------------------
# Project created by QtCreator 2010-03-28T13:06:00
# -------------------------------------------------
#include(../qextserialport/src/qextserialport.pri)

TARGET = qst
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    led.cpp \
    qextserialport.cpp

HEADERS += mainwindow.h \
    led.h \
    qextserialport.h

FORMS += mainwindow.ui \
    config.ui \
    about.ui
unix:DEFINES += _TTY_POSIX_
win32:DEFINES += _TTY_WIN_
CONFIG += debug
OTHER_FILES += 
RESOURCES += qst.qrc
