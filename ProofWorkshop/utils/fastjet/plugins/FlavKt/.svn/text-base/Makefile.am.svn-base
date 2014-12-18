SUBDIRS = fastjet

if MONOLITHIC_PLUGINS
noinst_LTLIBRARIES = libFlavKtPlugin.la
else
lib_LTLIBRARIES = libFlavKtPlugin.la
endif
libFlavKtPlugin_la_CXXFLAGS = $(AM_CXXFLAGS) -I$(srcdir) -I$(srcdir)/../../include
libFlavKtPlugin_la_SOURCES = types.f90 io_utils.f90 lcl_dec.f90 alg_declarations.f90 assertions.f90 alt_flavclus.f90 warnings_and_errors.f90 NameSelect.f90 dpsorter.f90 dpktclus_gen.f90 ktflav.f90 ktflavf77.f90 FlavKtPlugin.cc

EXTRA_DIST = makefile.static JetIModes.h ktflavf77.h

