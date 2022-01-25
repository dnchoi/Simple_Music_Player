#-------------------------------------------------
#
# Project created by QtCreator 2020-05-19T17:16:52
#
#-------------------------------------------------

QT       += core gui network multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Simple_Music_Player
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h \
        packet_definitions.h

FORMS += \
        mainwindow.ui


#INCLUDEPATH += /opt/intel/openvino/opencv/include
#LIBS += -L/opt/intel/openvino/opencv/lib \
#-lopencv_calib3d \
#-lopencv_core \
#-lopencv_dnn \
#-lopencv_features2d \
#-lopencv_flann \
#-lopencv_gapi \
#-lopencv_highgui \
#-lopencv_imgcodecs \
#-lopencv_imgproc \
#-lopencv_ml \
#-lopencv_objdetect \
#-lopencv_photo \
#-lopencv_stitching \
#-lopencv_videoio_ffmpeg \
#-lopencv_videoio_gstreamer \
#-lopencv_videoio_intel_mfx \
#-lopencv_videoio \
#-lopencv_video
INCLUDEPATH += /usr/local/include/opencv4
LIBS += -L/usr/local/lib \
-lopencv_calib3d \
-lopencv_core \
-lopencv_dnn \
-lopencv_features2d \
-lopencv_flann \
-lopencv_gapi \
-lopencv_highgui \
-lopencv_imgcodecs \
-lopencv_imgproc \
-lopencv_ml \
-lopencv_objdetect \
-lopencv_photo \
-lopencv_stitching \
-lopencv_videoio \
-lopencv_video
-lopencv_dnn

## Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icon.qrc
