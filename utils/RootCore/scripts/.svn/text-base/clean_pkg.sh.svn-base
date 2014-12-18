#!/bin/bash

source "`dirname $0`/preamble.sh" "$0"

pkgname="`basename $1`"
pkg="`grep /"$pkgname"$ $pkgfile`"
if test "$pkg" == ""
then
    echo package \"$1\" not found
    exit
fi

echo cleaning $pkg
cd $pkg
rm -rf bin obj StandAlone `$ROOTCOREDIR/scripts/get_field.sh cmt/Makefile.RootCore PACKAGE_CLEAN`

if test "$ROOTCOREOBJ" != ""
then
    rm -rf $ROOTCOREOBJ/`basename $pkg`
fi
