#!/bin/bash

source "`dirname $0`/preamble.sh" "$0"

if test -f $ROOTCOREBIN/lib/libgc.dylib -a -f $ROOTCOREBIN/lib/libgccpp.dylib
then
    export DYLD_INSERT_LIBRARIES=$ROOTCOREBIN/lib/libgc.dylib:$ROOTCOREBIN/lib/libgccpp.dylib
elif test -f $ROOTCOREBIN/lib/libgc.so -a -f $ROOTCOREBIN/lib/libgccpp.so
then
    export LD_PRELOAD=$ROOTCOREBIN/lib/libgc.so:$ROOTCOREBIN/lib/libgccpp.so
fi

exec root $*
