QT -= gui
QT += core network sql

CONFIG += c++11 console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        src/databaseengine.cpp \
        src/main.cpp \
        src/servercore.cpp

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
        src/databaseengine.h \
        src/servercore.h \
        src/user.h

INCLUDEPATH += src
