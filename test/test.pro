TEMPLATE = app
TARGET = rheda-messenger-tests
QT += testlib sql
CONFIG += qt console warn_on depend_includepath testcase

PATH_APP = ../server/src
INCLUDEPATH += $$PATH_APP

HEADERS += \
    testcase.h \
    $$PATH_APP/databaseengine.h

SOURCES += \
    $$PATH_APP/databaseengine.cpp \
    testcase.cpp


