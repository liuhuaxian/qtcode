#-------------------------------------------------
#
# Name：  Qt Creator Project Demo
# Author：Delphi Tang 
# Date：  2015-08-24
#
#-------------------------------------------------

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HelloWorld
TEMPLATE = app

INCLUDEPATH += E:/BCC/include \
               E:/VC/include

SOURCES += Main.cpp \
           HelloWorld.cpp

HEADERS += HelloWorld.h

FORMS   += HelloWorld.ui

RC_FILE += MyIco.rc

LIBS    += -LE:/vlc-1.11/sdk/lib

CONFIG  += warn_on debug

#
# if 'debug' option is set for CONFIG
#
CONFIG(debug) {
    DEFINES += DEBUG_LOG
    SOURCES += DebugLog.cpp
    HEADERS += DebugLog.h
}