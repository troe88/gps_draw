#-------------------------------------------------
#
# Project created by QtCreator 2015-05-01T12:30:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = draw_test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mygraphicsview.cpp \
    myscene.cpp

HEADERS  += mainwindow.h \
    mygraphicsview.h \
    myscene.h

FORMS    += mainwindow.ui

LIBS += -lgps
