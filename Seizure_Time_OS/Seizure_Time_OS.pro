#-------------------------------------------------
#
# Project created by QtCreator 2014-08-28T12:39:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Seizure_Time_OS
TEMPLATE = app


SOURCES += main.cpp\
        seizuretimecore.cpp \
    mainmenu.cpp \
    quitconfirmdialog.cpp \
    directorylistdialog.cpp \
    datedialog.cpp \
    helpdialog.cpp \
    pcbcontrol.cpp \
    pcb.cpp \
    pcbqueue.cpp \
    pcbmanagerdialog.cpp

HEADERS  += seizuretimecore.h \
    mainmenu.h \
    mainmenu.h \
    quitconfirmdialog.h \
    directorylistdialog.h \
    datedialog.h \
    helpdialog.h \
    pcbcontrol.h \
    pcb.h \
    pcbqueue.h \
    pcbmanagerdialog.h

FORMS    += seizuretimecore.ui \
    mainmenu.ui

RESOURCES +=
