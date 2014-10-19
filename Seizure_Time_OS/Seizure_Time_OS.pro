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
    pcbcontrol.cpp \
    pcb.cpp \
    pcbqueue.cpp \
    pcbmanagerdialog.cpp \
    globals.cpp \
    textdialog.cpp \
    multipagedialog.cpp \
    processschedulerdialog.cpp \
    processscheduler.cpp \
    memorymanager.cpp

HEADERS  += seizuretimecore.h \
    mainmenu.h \
    mainmenu.h \
    quitconfirmdialog.h \
    directorylistdialog.h \
    datedialog.h \
    pcbcontrol.h \
    pcb.h \
    pcbqueue.h \
    pcbmanagerdialog.h \
    globals.h \
    textdialog.h \
    multipagedialog.h \
    processschedulerdialog.h \
    processscheduler.h \
    memorymanager.h

FORMS    += seizuretimecore.ui \
    mainmenu.ui \
    pcbmanagerdialog.ui \
    processschedulerdialog.ui

RESOURCES +=
