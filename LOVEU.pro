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
    usage.cpp \
    setmemory.cpp \
    def_function.cpp \
    def_system.cpp \
    def_triggered.cpp \
    setbirthday.cpp \
    def_toolButton.cpp

HEADERS  += mainwindow.h \
    settime.h \
    info.h \
    usage.h \
    setmemory.h \
    setbirthday.h

FORMS    += mainwindow.ui \
    settime.ui \
    info.ui \
    usage.ui \
    setmemory.ui \
    setbirthday.ui

RC_FILE += LOVEU.rc

RESOURCES += \
    source.qrc
