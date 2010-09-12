# -*- mode:make; tab-width:2; -*-

.DEFAULT: all

TARGETS   := client qwctlapp
SUBMAKES  := $(dir $(wildcard */Makefile))
SUBQMAKES := $(dir $(wildcard */qmake.pro))

all distclean: $(SUBMAKES)
	@for i in $^; do make -C $$i $@; done
	@find -type f -\( -name "*~" -or -name "#*" -\) -delete;

qmake: $(SUBQMAKES)
	@for i in $^; do cd $$i; qmake; cd ..; done

run: $(TARGETS)
	@for i in $^; do ($$i/$$i &); done
