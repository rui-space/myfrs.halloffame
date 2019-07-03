#-------------------------------------------------
#
# Project created by QtCreator 2019-06-04T22:22:12
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = halloffame
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

INCLUDEPATH += include /usr/local/include /usr/local/protobuf/include /usr/local/mycpp/include
LIBS += -ljsoncpp /usr/local/mycpp/libmycpp.so
LIBS += -L /usr/local/protobuf/lib -lprotobuf

SOURCES += \
        src/main.cpp \
        src/widget.cpp \
        src/Common.pb.cc \
        src/faguang.cpp \
        src/guangxian.cpp \
        src/historythread.cpp \
        src/huizhanglishi.cpp \
        src/ji.cpp \
        src/kuang.cpp \
        src/mingrentang.cpp \
        src/pianming.cpp \
        src/qiehuantouxiang.cpp \
        src/xingxing.cpp \
        src/xunzhang.cpp \
        src/yuan.cpp \
        src/yuanguang.cpp \
        src/yue.cpp \
        src/zhengzaijinxing.cpp \
        src/zhou.cpp \
    src/main_service.cpp \
    src/read_task.cpp \
    src/parse_task.cpp \
    src/currentthread.cpp \
    src/startthread.cpp \
    src/config.cpp

HEADERS += \
        include/Common.pb.h \
        include/widget.h \
        include/Common.pb.h \
        include/faguang.h \
        include/guangxian.h \
        include/historythread.h \
        include/huizhanglishi.h \
        include/ji.h \
        include/kuang.h \
        include/mingrentang.h \
        include/pianming.h \
        include/qiehuantouxiang.h \
        include/xingxing.h \
        include/xunzhang.h \
        include/yuan.h \
        include/yuanguang.h \
        include/yue.h \
        include/zhengzaijinxing.h \
        include/zhou.h \
    include/main_service.h \
    include/parse_task.h \
    include/read_task.h \
    include/currentthread.h \
    include/startthread.h \
    include/config.h \
    include/main.h

FORMS += \
        widget.ui

DISTFILES += \
    CMakeLists.txt \
    bin/configuration.json \
    proto/Common.proto \ 
    debian/prerm \
    debian/postinst \
    debian/control \
    debian/conffiles \
    halloffame.service \
    halloffame.desktop

DESTDIR = bin
OBJECTS_DIR = .obj
MOC_DIR = .moc
UI_DIR = .ui

# Default rules for deployment.
target.path = bin
!isEmpty(target.path): INSTALLS += target
