TEMPLATE = app
TARGET = qwctlapp
DEPENDPATH += .
INCLUDEPATH += ../dbusdefinition
QT += dbus webkit
CONFIG  += debug
FORMS   += qwctlapp.ui
HEADERS += \
	qwctlapp.h \
	clients_model.h \
	../dbusdefinition/qwctl_proxy.h

SOURCES += \
	qwctlapp.cpp \
	clients_model.cpp \
	../dbusdefinition/qwctl_proxy.cpp

QMAKE_CXXFLAGS += -std=gnu++0x
