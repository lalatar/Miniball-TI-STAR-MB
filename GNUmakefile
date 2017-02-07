# --------------------------------------------------------------
# GNUmakefile for MiniBall library.  Gabriele Cosmo, 06/04/98.
# Modifications by Hans Boie 
# --------------------------------------------------------------

name := MiniBall
G4TARGET := $(name)
G4EXLIB := true

ROOTCFLAGS   := $(shell root-config --cflags)
ROOTLIBS     := $(shell root-config --libs)
ROOTGLIBS    := $(shell root-config --glibs)

ifndef MBLIB
  MBLIB := $(HOME)/lib
#  MBLIB := ./lib
endif

ifndef G4INSTALL
  G4INSTALL = ../../..
endif

.PHONY: all
all: mblib

include $(G4INSTALL)/config/architecture.gmk

CPPFLAGS += $(MB_DEFINITIONS) -g $(INCFLAGS) $(ROOTCFLAGS)
LDFLAGS  += $(ROOTLIBS) $(ROOTGLIBS)

include $(G4INSTALL)/config/binmake.gmk

mblib: lib
	@echo "...copying library to destination directory $(MBLIB)"
	@if [ ! -d $(MBLIB) ] ; then mkdir $(MBLIB) ;fi
	@cp $(G4TMP)/$(G4SYSTEM)/$(G4TARGET)/lib$(G4TARGET).so $(MBLIB)/

examples: Ex01 Ex02 Ex03 Ex04 Ex05 HPGeEff

Ex01:
	@cd examples/Ex01; make
Ex02:
	@cd examples/Ex02; make
Ex03:
	@cd examples/Ex03; make
Ex04:
	@cd examples/Ex04; make
Ex05:
	@cd examples/Ex05; make
HPGeEff:
	@cd examples/efficiency; make

# ---------------- create tar file ----------------

tar:
	@echo "creating zipped tar-ball ... "
	tar -chvzf MiniballSource.tar.gz src/*.cc include/*.hh GNUmakefile \
	Doxyfile.conf FirstSteps-HowTo.txt MiniBall.doxy README ToDo \
	doc/* lib/*
