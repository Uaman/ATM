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
    Classes/GUI/FramesAndWidgets/TakingMoney.cpp \
    Classes/logic/Account.cpp \
    Classes/logic/ATM.cpp \
    Classes/logic/Card.cpp \
    Classes/logic/DataStorage.cpp \
    Classes/logic/MD5.cpp \
    Classes/GUI/FramesAndWidgets/AnotherSumFrame.cpp


HEADERS += \
    Classes/GUI/MenuStates.h \
    Classes/GUI/FramesAndWidgets/MainWindow.h \
    Classes/GUI/FramesAndWidgets/MainMenu.h \
    Classes/GUI/FramesAndWidgets/MainWindowFrame.h \
    Classes/GUI/FramesAndWidgets/TakingMoney.h \
    Classes/logic/Account.h \
    Classes/logic/ATM.h \
    Classes/logic/Card.h \
    Classes/logic/DataStorage.h \
    Classes/logic/MD5.h \
    Classes/logic/BankData.h \
    Classes/GUI/FramesAndWidgets/AnotherSumFrame.h

FORMS += \
    Classes/GUI/FramesAndWidgets/MainWindow.ui \
    Classes/GUI/FramesAndWidgets/MainMenu.ui \
    Classes/GUI/FramesAndWidgets/MainWindowFrame.ui \
    Classes/GUI/FramesAndWidgets/TakingMoney.ui \
    Classes/GUI/FramesAndWidgets/AnotherSumFrame.ui


