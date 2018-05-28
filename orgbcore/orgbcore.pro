#-------------------------------------------------
#
# Project created by QtCreator 2018-05-27T08:29:22
#
#-------------------------------------------------

QT       -= gui
QT       += core

TARGET = orgbcore
TEMPLATE = lib

DEFINES += ORGBCORE_LIBRARY

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
  DESTDIR = ..\bin\
}

INCLUDEPATH += C:\opencv\build\include\

LIBS += -LC:\opencv\build\x86\vc14\lib\ \
        -lopencv_core2413d \
        -lopencv_highgui2413d \
        -lopencv_imgproc2413d \
        -lopencv_features2d2413d \
        -lopencv_calib3d2413d

SOURCES += \
        orgbcore.cpp \
    orgb_conveyor.cpp \
    orgb_operator.cpp \
    orgb_rgb2lccoperator.cpp \
    orgb_algorithm.cpp \
    orgb_rgb2lccalgorithm.cpp \
    orgb_lcc2orgboperator.cpp \
    orgb_lcc2orgbalgorithm.cpp \
    orgb_warm2coolalgorithm.cpp \
    orgb_w2coperator.cpp \
    orgb_orgb2lccalgorithm.cpp \
    orgb_orgb2lccoperator.cpp \
    orgb_lcc2rgbalgorithm.cpp \
    orgb_lcc2rgboperator.cpp

HEADERS += \
        orgbcore.h \
        orgbcore_global.h \ 
    orgb_conveyor.h \
    orgb_operator.h \
    orgb_rgb2lccoperator.h \
    orgb_algorithm.h \
    orgb_rgb2lccalgorithm.h \
    orgb_operator_list.h \
    orgb_agorithm_list.h \
    orgb_lcc2orgboperator.h \
    orgb_lcc2orgbalgorithm.h \
    orgb_warm2coolalgorithm.h \
    orgb_w2coperator.h \
    orgb_orgb2lccalgorithm.h \
    orgb_orgb2lccoperator.h \
    orgb_lcc2rgbalgorithm.h \
    orgb_lcc2rgboperator.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
