#-------------------------------------------------
#
# Project created by QtCreator 2016-03-12T19:47:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = autocorrelation
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11
SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    autocorrelation.cpp \
    utils.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    autocorrelation.h \
    utils.h

FORMS    += mainwindow.ui
