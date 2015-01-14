# -*- Makefile -*-
# This Makefile was generated automatically by the 'configure' script using
#    ./configure CXXFLAGS=-O2 -pipe -Wall -W -Woverloaded-virtual -pthread -stdlib=libc++ -std=c++11 -m64 -I/Users/Alex/Desktop/HEP/ROOT6/include -Qunused-arguments -DJETEDM_STANDALONE LDFLAGS=-O2 -mmacosx-version-min=10.10 -m64 FC=gfortran FCFLAGS=-O2 -fPIC --fastjet-config=/Users/Alex/Desktop/ProofAna/utils/fastjet/fastjet-config --prefix=/Users/Alex/Desktop/ProofAna/utils/fastjet/install-dir
# If you edit the processed version, any changes will be lost after the next configure
# (for developers, make sure you only edit Makefile.in)

# installation setup
SUBDIRS=SoftKiller
SUBDIRS.all=$(SUBDIRS:=.all)

# these will be overriden if the user specifies CXX or CXXFLAGS with configure
# they will also be overriden by definitions in subsiduary Makefiles
CXX=g++
CXXFLAGS=-O2 -Wall -g

# get any variables defined in the contrib-wide include
-include .Makefile.inc

# make invocations in subdirectories have an environment variable
# set so that they can alter their behaviour if need be 
# (e.g. for make check)
SUBMAKE= $(MAKE) FJCONTRIB_SUBMAKE=1

.PHONY: $(SUBDIRS) $(SUBDIRS.all) clean distclean check check_init install examples

all: $(SUBDIRS.all)

install: all $(SUBDIRS)

examples clean: $(SUBDIRS)

distclean: $(SUBDIRS) fragile-shared-distclean

check: check_init $(SUBDIRS)
	@echo ""
	@cat test_summary.tmp
	@printf "\n%d out of %d tests passed\n\n" `grep "Success" test_summary.tmp | wc -l` `grep "^  " test_summary.tmp | wc -l`
	@rm -f test_summary.tmp

check_init:
	@echo "Summary of tests" >  test_summary.tmp
	@echo "----------------" >> test_summary.tmp

# distclean removes the Makefile, but leaves in config.log
distclean:
	rm -f Makefile
	rm -f .Makefile.inc

# dirty hack to provide a shared library to CMS; this is extremely fragile
# and will be hopefully replaced with a more robust solution at some
# point in the future; note, that you must still do make install
# in order for all the headers to be installed
fragile-shared: libfastjetcontribfragile.dylib

fragile_SHARED_SRC_LIST=SoftKiller/SoftKiller.cc
libfastjetcontribfragile.dylib: $(fragile_SHARED_SRC_LIST)
	$(CXX) -dynamiclib -fPIC -DPIC $(CXXFLAGS) `$(FASTJETCONFIG) --cxxflags --libs` $(fragile_SHARED_SRC_LIST) -o libfastjetcontribfragile.dylib

fragile-shared-install: fragile-shared
	utils/install-sh -c -m 644 libfastjetcontribfragile.dylib $(PREFIX)/lib
	install_name_tool -id $(PREFIX)/lib/libfastjetcontribfragile.dylib  $(PREFIX)/lib/libfastjetcontribfragile.dylib 

fragile-shared-distclean:
	rm -f libfastjetcontribfragile.dylib

$(SUBDIRS):
	+$(SUBMAKE) -C $@ $(MAKECMDGOALS)

$(SUBDIRS.all):
	+$(SUBMAKE) -C $(basename $@)
