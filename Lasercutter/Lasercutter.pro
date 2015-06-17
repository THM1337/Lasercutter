#-------------------------------------------------
#
# Project created by QtCreator 2015-05-26T18:09:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lasercutter
TEMPLATE = app


SOURCES += main.cpp\
        lasercutter.cpp \
    Parser.cpp \
    zeichenbrett.cpp

HEADERS  += lasercutter.h \
    Parser.h \
    zeichenbrett.h

FORMS    += lasercutter.ui

CONFIG	+= c++11
