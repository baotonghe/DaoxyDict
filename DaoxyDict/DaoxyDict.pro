#-------------------------------------------------
#
# Project created by QtCreator 2015-05-15T20:35:50
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ../DaoxyDict/bin/DaoxyDict
TEMPLATE = app

INCLUDEPATH += header

SOURCES += source/main.cpp\
        source/DaoxyDictMainWindow.cpp \
    source/DaoxyQSSUtils.cpp \
    source/DaoxyDictHttpService.cpp

HEADERS += header/DaoxyDictMainWindow.h \
    header/DaoxyQSSUtils.h \
    header/DaoxyDictHttpService.h

RESOURCES += \
    resource/daoxydict.qrc
