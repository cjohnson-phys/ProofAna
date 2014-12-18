
# Makefile generated automatically by /Users/gsalam/scripts/mkcxx.pl '-f' '-i' '-I..' '-l' '-L.. -lFlavKtPlugin -lgfortran'
# run 'make make' to update it if you add new files

CXXFLAGS = -Wall -g -O2

FJCONFIG = fastjet-config
INCLUDE += `$(FJCONFIG) --cxxflags`
LIBRARIES  += `$(FJCONFIG) --libs --plugins`
INCLUDE += $(LCLINCLUDE)

COMMONSRC = 
F77SRC = 
COMMONOBJ = 

PROGSRC = fastjet-example.cc standalone-example.cc
PROGOBJ = fastjet-example.o standalone-example.o

INCLUDE += -I..
LIBRARIES += -L.. -lFlavKtPlugin -lgfortran


all:  fastjet-example standalone-example 


fastjet-example: fastjet-example.o  $(COMMONOBJ)
	$(CXX) $(LDFLAGS) -o $@ $@.o $(COMMONOBJ) $(LIBRARIES)

standalone-example: standalone-example.o  $(COMMONOBJ)
	$(CXX) $(LDFLAGS) -o $@ $@.o $(COMMONOBJ) $(LIBRARIES)


make:
	/Users/gsalam/scripts/mkcxx.pl '-f' '-i' '-I..' '-l' '-L.. -lFlavKtPlugin -lgfortran'

clean:
	rm -vf $(COMMONOBJ) $(PROGOBJ)

realclean: clean
	rm -vf  fastjet-example standalone-example 

.cc.o:         $<
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@
.cpp.o:         $<
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@
.C.o:         $<
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@
.f.o:         $<
	$(F77) $(FFLAGS) -c $< -o $@


depend:
	makedepend  $(LCLINCLUDE) -Y --   -- $(COMMONSRC) $(PROGSRC)
# DO NOT DELETE
