#-------------------------------------------------
#
# Project created by QtCreator 2023-07-04T17:29:02
#
#-------------------------------------------------

QT       += core gui network

TARGET = RPC
TEMPLATE = app

win32:INCLUDEPATH += E:/Qt/security/include
win32:LIBS += ./libeay32.lib

SOURCES += main.cpp\
    login.cpp \
    register.cpp \
    userinfo.cpp \
    user.cpp \
    clientdashboard.cpp \
    des.cpp \
    share.cpp \
    loggedinusers.cpp \
    fileinfoitem.cpp \
    fileinfo.cpp \
    manage.cpp \
    server.cpp \
    client.cpp \
    socketthread.cpp

HEADERS  +=    login.h \
    register.h \
    userinfo.h \
    user.h \
    clientdashboard.h \
    des.h \
    share.h \
    loggedinusers.h \
    fileinfoitem.h \
    fileinfo.h \
    manage.h \
    server.h \
    client.h \
    socketthread.h

FORMS    +=    login.ui \
    register.ui \
    clientdashboard.ui \
    manage.ui

RESOURCES += \
    resource.qrc

RC_FILE = myapp.rc
