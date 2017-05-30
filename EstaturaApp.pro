#-------------------------------------------------
#
# Project created by QtCreator 2017-05-24T23:33:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EstaturaApp
TEMPLATE = app


SOURCES += main.cpp\
        inicio.cpp \
    procesadorimagenes.cpp

HEADERS  += inicio.h \
    procesadorimagenes.h

FORMS    += inicio.ui

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_videoio -lopencv_video

RESOURCES += \
    imagenes.qrc
