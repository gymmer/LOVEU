#-------------------------------------------------
#
# Project created by QtCreator 2015-01-17T14:39:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LOVEU
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    settime.cpp \
    info.cpp \
    help.cpp

HEADERS  += mainwindow.h \
    settime.h \
    info.h \
    help.h

FORMS    += mainwindow.ui \
    settime.ui \
    info.ui \
    help.ui

RC_FILE += LOVEU.rc

RESOURCES += \
    source.qrc
