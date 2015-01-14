# -*- Makefile -*-
# This Makefile was generated automatically by the 'configure' script using
#    ./configure CXXFLAGS=-O2 -Wall -fPIC -pthread -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/5.34.19-x86_64-slc5-gcc4.3/include -fno-builtin-memcmp -DJETEDM_STANDALONE LDFLAGS=-O2 -m64 FC=gfortran FCFLAGS=-O2 -fPIC --fastjet-config=/sx/caj24/testarea/ProofAna/utils/fastjet/fastjet-config --prefix=/sx/caj24/testarea/ProofAna/utils/fastjet/install-dir
# If you edit the processed version, any changes will be lost after the next configure
# (for developers, make sure you only edit Makefile.in)

# installation setup
SUBDIRS=SoftKiller Nsubjettiness JetFFMoments EnergyCorrelator ConstituentSubtractor VariableR JetCleanser GenericSubtractor JetsWithoutJets RecursiveTools SubjetCounting ScJet
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
fragile-shared: libfastjetcontribfragile.so

fragile_SHARED_SRC_LIST=SoftKiller/SoftKiller.cc Nsubjettiness/Nsubjettiness.cc Nsubjettiness/Njettiness.cc Nsubjettiness/NjettinessPlugin.cc Nsubjettiness/MeasureFunction.cc Nsubjettiness/AxesFinder.cc Nsubjettiness/WinnerTakeAllRecombiner.cc Nsubjettiness/NjettinessDefinition.cc JetFFMoments/JetFFMoments.cc EnergyCorrelator/EnergyCorrelator.cc ConstituentSubtractor/ConstituentSubtractor.cc VariableR/VariableRPlugin.cc JetCleanser/JetCleanser.cc GenericSubtractor/GenericSubtractor.cc JetsWithoutJets/JetsWithoutJets.cc JetsWithoutJets/EventStorage.cc RecursiveTools/Recluster.cc RecursiveTools/RecursiveSymmetryCutBase.cc RecursiveTools/ModifiedMassDropTagger.cc RecursiveTools/SoftDrop.cc SubjetCounting/SubjetCounting.cc ScJet/ScJet.cc
libfastjetcontribfragile.so: $(fragile_SHARED_SRC_LIST)
	$(CXX) -shared -fPIC -DPIC $(CXXFLAGS) `$(FASTJETCONFIG) --cxxflags --libs` $(fragile_SHARED_SRC_LIST) -o libfastjetcontribfragile.so

fragile-shared-install: fragile-shared
	utils/install-sh -c -m 644 libfastjetcontribfragile.so $(PREFIX)/lib
	

fragile-shared-distclean:
	rm -f libfastjetcontribfragile.so

$(SUBDIRS):
	+$(SUBMAKE) -C $@ $(MAKECMDGOALS)

$(SUBDIRS.all):
	+$(SUBMAKE) -C $(basename $@)
