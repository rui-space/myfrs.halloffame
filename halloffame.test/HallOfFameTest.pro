QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

INCLUDEPATH += /usr/local/include /usr/local/protobuf/include
LIBS += -L /usr/local/protobuf/lib -lprotobuf

DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += ASIO_STANDALONE

SOURCES += \
        Common.pb.cc \
        main.cpp
HEADERS += \
    Common.pb.h
