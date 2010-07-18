TEMPLATE = app
TARGET = client
DEPENDPATH += .
INCLUDEPATH += ../dbusdefinition
QT += dbus
CONFIG  += debug
FORMS   += client.ui
HEADERS += client.h ../dbusdefinition/qwctl_adaptor.h
SOURCES += client.cpp ../dbusdefinition/qwctl_adaptor.cpp
QMAKE_CXXFLAGS += -std=gnu++0x
