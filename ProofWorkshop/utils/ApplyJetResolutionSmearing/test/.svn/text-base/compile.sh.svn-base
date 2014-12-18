#!/bin/bash

error() { echo ; echo "ERROR:"; echo "  $*"; kill -SIGINT $$; }

[[ -z $ROOTCOREDIR ]] && error "You need to setup RootCore first!"

$ROOTCOREDIR/scripts/compile.sh || error "Failed compiling RootCore packages."

  # let rootcore tell us about library paths
ldflags=$($ROOTCOREDIR/scripts/get_ldflags.sh ApplyJetResolutionSmearing ApplyJetCalibration)
flagsNlibs="$($ROOTSYS/bin/root-config --cflags --glibs) -lTreePlayer -lXMLParser $ldflags"

includes="-I$ROOTCOREDIR/include"

echo
echo "  My compilation flags:"
echo $flagsNlibs
echo

exec=test_smear.exe
code=JetResolutionTest.C
rm -f $exec

g++ $flagsNlibs $includes -o $exec $code || error "Compilation failed!"

echo ; echo "Compilation successful"; 
echo ; echo "Will now run $exec"; echo ; echo;
./$exec


