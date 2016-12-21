#-------------------------------------------------
#
# Project created by QtCreator 2016-12-19T10:06:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QGraphicsViewArch
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mycustomitem.cpp \
    cgraphicsscene.cpp \
    gaugelist.cpp \
    gauge.cpp \
    attitude.cpp \
    bargauge.cpp

HEADERS  += mainwindow.h \
    mycustomitem.h \
    cgraphicsscene.h \
    gaugelist.h \
    gauge.h \
    attitude.h \
    bargauge.h

INCLUDEPATH += .
INCLUDEPATH += /usr/local/include
INCLUDEPATH += /usr/local/include/opencv
INCLUDEPATH += /usr/local/include/opencv2
INCLUDEPATH += /usr/local/include/opencv2/core
INCLUDEPATH += /usr/local/include/opencv2/highgui
INCLUDEPATH += /usr/local/include/opencv2/imgproc
INCLUDEPATH += /usr/local/include/opencv2/flann
INCLUDEPATH += /usr/local/include/opencv2/photo
INCLUDEPATH += /usr/local/include/opencv2/video
INCLUDEPATH += /usr/local/include/opencv2/features2d
INCLUDEPATH += /usr/local/include/opencv2/objdetect
INCLUDEPATH += /usr/local/include/opencv2/calib3d
INCLUDEPATH += /usr/local/include/opencv2/ml
INCLUDEPATH += /usr/local/include/opencv2/contrib
LIBS += `pkg-config opencv --cflags --libs`


FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
