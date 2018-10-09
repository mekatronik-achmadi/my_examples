#-------------------------------------------------
#
# Project created by QtCreator 2014-03-16T18:28:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tugas1
TEMPLATE = app


SOURCES += main.cpp\
        tgs1.cpp

HEADERS  += tgs1.h

FORMS    += tgs1.ui

LIBS += -lopencv_core
LIBS += -lopencv_imgproc
LIBS += -lopencv_highgui
