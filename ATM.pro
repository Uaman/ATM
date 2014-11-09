#-------------------------------------------------
#
# Project created by QtCreator 2014-10-01T12:21:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ATM
TEMPLATE = app

SOURCES += \
    Classes/GUI/MenuStates.cpp \
    Classes/main.cpp \
    Classes/GUI/FramesAndWidgets/MainWindow.cpp \
    Classes/GUI/FramesAndWidgets/MainMenu.cpp \
    Classes/GUI/FramesAndWidgets/MainWindowFrame.cpp \
    Classes/GUI/FramesAndWidgets/TakingMoney.cpp

HEADERS += \
    Classes/GUI/MenuStates.h \
    Classes/GUI/FramesAndWidgets/MainWindow.h \
    Classes/GUI/FramesAndWidgets/MainMenu.h \
    Classes/GUI/FramesAndWidgets/MainWindowFrame.h \
    Classes/GUI/FramesAndWidgets/TakingMoney.h

FORMS += \
    Classes/GUI/FramesAndWidgets/MainWindow.ui \
    Classes/GUI/FramesAndWidgets/MainMenu.ui \
    Classes/GUI/FramesAndWidgets/MainWindowFrame.ui \
    Classes/GUI/FramesAndWidgets/TakingMoney.ui

