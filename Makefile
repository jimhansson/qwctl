# -*- mode:make; tab-width:2; -*-

.DEFAULT: all

DIRS := client qwctlapp

all distclean: $(DIRS)
	@for i in $^; do make -C $$i $@; done

qmake: $(DIRS)
	@for i in $^; do cd $$i; qmake; cd ..; done

run: $(DIRS)
	@for i in $^; do ($$i/$$i &); done
