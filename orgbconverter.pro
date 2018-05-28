#-------------------------------------------------
#
# Project created by QtCreator 2018-05-26T16:30:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = orgbconverter
TEMPLATE = app

SUBDIRS += orgbcore

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

win32 {
  DESTDIR = ..\orgbconverter\bin\
}

INCLUDEPATH += C:\opencv\build\include\
INCLUDEPATH += orgbcore\

LIBS += -LC:\opencv\build\x86\vc14\lib\ \
        -lopencv_core2413d \
        -lopencv_highgui2413d \
        -lopencv_imgproc2413d \
        -lopencv_features2d2413d \
        -lopencv_calib3d2413d
LIBS += -LD:\code\orgbconverter\bin\ \
        -lorgbcore

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    resources.qrc
