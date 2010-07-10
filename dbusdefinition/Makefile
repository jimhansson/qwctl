# -*- mode:make; tab-width:2; -*-

# Makefile for running qdbusxml2cpp for creating adaptor and proxy code.

DBUSXML2CPP := qdbusxml2cpp

n := qwctl

TARGETS := $(addprefix $n,_proxy.h _proxy.cpp _adaptor.h _adaptor.cpp)

$(TARGETS): $(wildcard *.xml)
	$(DBUSXML2CPP) -c QWCtlAdaptor -a $n_adaptor $<
	$(DBUSXML2CPP) -c QWCtl        -p $n_proxy   $<

clean distclean:
	$(RM) $(TARGETS) *~
