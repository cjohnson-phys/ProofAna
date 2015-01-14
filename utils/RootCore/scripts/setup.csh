if $?ROOTSYS then
    true
else
    setenv ROOTSYS `root-config --prefix`
    test $? -ne 0 && echo no valid root version found, please set up root && return 1
endif

test "x$ROOTSYS" != "x/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/5.34.19-x86_64-slc5-gcc4.3" && echo ROOTSYS=$ROOTSYS not /cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/5.34.19-x86_64-slc5-gcc4.3 && echo please set up correct root version or follow the instructions at && echo \ \ https://twiki.cern.ch/twiki/bin/viewauth/Atlas/RootCore#If_Something_Goes_Wrong && return 1

setenv ROOTCOREDIR /sx/caj24/testarea/ProofAna_git/utils/RootCore
if $?ROOTCOREBIN then
    true
else
    setenv ROOTCOREBIN /sx/caj24/testarea/ProofAna_git/utils/RootCore
endif
test \! -d "$ROOTCOREBIN" && echo output directory not found, please create it && echo "  mkdir $ROOTCOREBIN" && return 1

setenv PATH $ROOTCOREBIN/bin:$PATH
if $?LD_LIBRARY_PATH then
    setenv LD_LIBRARY_PATH $ROOTCOREBIN/lib:$LD_LIBRARY_PATH
endif
if $?DYLD_LIBRARY_PATH then
    setenv DYLD_LIBRARY_PATH $ROOTCOREBIN/lib:$DYLD_LIBRARY_PATH
endif
if $?PYTHONPATH then
    setenv PYTHONPATH $ROOTCOREBIN/python:$PYTHONPATH
else
    setenv PYTHONPATH $ROOTCOREBIN/python
endif

mkdir -p $ROOTCOREBIN/bin

# this is my way of creating the rc link without introducing race conditions
test -e $ROOTCOREBIN/bin/rc && test \! -f $ROOTCOREBIN/bin/rc && rm -f $ROOTCOREBIN/bin/rc || true
test -f $ROOTCOREBIN/bin/rc || ln -s $ROOTCOREDIR/scripts/rc.sh $ROOTCOREBIN/bin/rc || test -f $ROOTCOREBIN/bin/rc

true
