#-------------------------------------------------
#
# Project created by QtCreator 2016-11-09T20:59:56
#
#-------------------------------------------------

QT += core gui
QT += gamepad
QT += network websockets
android: QT += androidextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ViRHaS
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamepadmonitor.cpp \
    controlstransmission.cpp \
    mouseeventlabel.cpp \
    camerastream.cpp \
    websocketclient.cpp \
    screeninitialization.cpp \
    buttonsclass.cpp \
    settingsclass.cpp \
    gamepadkeyclass.cpp \
    screenmanipulation.cpp \
    errorclass.cpp \
    imagewidget.cpp \
    vibrator.cpp

HEADERS  += mainwindow.h \
    screenconstants.h \
    gamepadmonitor.h \
    controlstransmission.h \
    mouseeventlabel.h \
    camerastream.h \
    websocketclient.h \
    actions_enum.h \
    status_enum.h \
    server_information.h \
    robot_structures.h \
    screeninitialization.h \
    buttonsclass.h \
    settingsclass.h \
    gamepadkeyclass.h \
    screenmanipulation.h \
    windows_enum.h \
    errorclass.h \
    errors.h \
    imagewidget.h \
    vibrator.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

RESOURCES += \
    resources.qrc

DISTFILES += \
    android-sources/AndroidManifest.xml

    ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android-sources

