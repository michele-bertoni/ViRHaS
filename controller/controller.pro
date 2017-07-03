QT	   += core network websockets serialport

LIBS += -lv4l2 -lv4lconvert
TARGET = controller
CONFIG   += console
CONFIG   -= app_bundle
QMAKE_CXXFLAGS += -std=c++11

TEMPLATE = app


SOURCES += main.cpp \
        capturethread.cpp \
    captureclass.cpp \
    mainclass.cpp \
    controlclass.cpp \
    websocketserver.cpp \
    arduinocommunication.cpp

HEADERS += \
        capturethread.h \
    captureclass.h \
    mainclass.h \
    controlclass.h \
    vidsett.h \
    status_enum.h \
    websocketserver.h \
    actions_enum.h \
    events_enum.h \
    speedvector.h \
    arduinocommunication.h

DISTFILES += \
    packages.txt \
    message_legend

RESOURCES += \
    resources.qrc
