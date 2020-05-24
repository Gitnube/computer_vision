#-------------------------------------------------
#
# Project created by QtCreator 2017-12-28T11:20:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = vision1_hiding
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        acoregenerator.cpp \
        dxcoregenerator.cpp \
        dycoregenerator.cpp \
        emptyimageexpander.cpp \
        fillimageexpander.cpp \
        gausscoregenerator.cpp \
        imagenormalizer.cpp \
        mainwindow.cpp \
        mirrorimageexpander.cpp \
        simplefilter.cpp \
        sobelfilter.cpp

HEADERS  += mainwindow.h \
    acoregenerator.h \
    dxcoregenerator.h \
    dycoregenerator.h \
    emptyimageexpander.h \
    fillimageexpander.h \
    gausscoregenerator.h \
    icoregenerator.h \
    iimageexpander.h \
    iimagefilter.h \
    imagenormalizer.h \
    mirrorimageexpander.h \
    simplefilter.h \
    sobelfilter.h

FORMS    += mainwindow.ui
