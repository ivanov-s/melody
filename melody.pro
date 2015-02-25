#-------------------------------------------------
#
# Project created by QtCreator 2015-02-21T15:39:35
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = melody
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamewindow.cpp

HEADERS  += mainwindow.h \
    gamewindow.h

FORMS    += mainwindow.ui \
    gamewindow.ui

RESOURCES += mp3.qrc
