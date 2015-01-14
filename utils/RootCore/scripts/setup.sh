if test \! -z "${ROOTCOREDIR:+x}"
then
    echo already using a valid RootCore installation:
    echo "  $ROOTCOREDIR"
    return 1
fi

if test -z "${ROOTSYS:+x}"
then
    export ROOTSYS=`root-config --prefix`
    test $? -ne 0 && echo no valid root version found, please set up root && return 1
fi

#test "x$ROOTSYS" != "x/Users/Alex/Desktop/HEP/ROOT6" && echo ROOTSYS=$ROOTSYS not /Users/Alex/Desktop/HEP/ROOT6 && echo please set up correct root version or follow the instructions at && echo \ \ https://twiki.cern.ch/twiki/bin/viewauth/Atlas/RootCore#If_Something_Goes_Wrong && return 1

export ROOTCOREDIR=/Users/Alex/Desktop/HEP/gFEX/ProofAna/utils/RootCore
test -z "${ROOTCOREBIN:+x}" && export ROOTCOREBIN=/Users/Alex/Desktop/HEP/gFEX/ProofAna/utils/RootCore
test \! -d "$ROOTCOREBIN" && echo output directory not found, please create it && echo "  mkdir $ROOTCOREBIN" && return 1

export PATH=$ROOTCOREBIN/bin:$PATH
export LD_LIBRARY_PATH=$ROOTCOREBIN/lib:$LD_LIBRARY_PATH
export DYLD_LIBRARY_PATH=$ROOTCOREBIN/lib:$DYLD_LIBRARY_PATH
export PYTHONPATH=$ROOTCOREBIN/python:$PYTHONPATH

mkdir -p $ROOTCOREBIN/bin

# this is my way of creating the rc link without introducing race conditions
test -e $ROOTCOREBIN/bin/rc && test \! -f $ROOTCOREBIN/bin/rc && rm -f $ROOTCOREBIN/bin/rc || true
test -f $ROOTCOREBIN/bin/rc || ln -s $ROOTCOREDIR/scripts/rc.sh $ROOTCOREBIN/bin/rc || test -f $ROOTCOREBIN/bin/rc

true
