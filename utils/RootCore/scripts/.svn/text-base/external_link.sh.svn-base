#!/bin/bash

if test \! -e configured
then
    echo failed to find $name installation
    exit 1
fi

bindir=`$ROOTCOREDIR/scripts/get_field.sh configured bindir`
incdir=`$ROOTCOREDIR/scripts/get_field.sh configured incdir`
libdir=`$ROOTCOREDIR/scripts/get_field.sh configured libdir`
binname=`$ROOTCOREDIR/scripts/get_field.sh configured binname`
incname=`$ROOTCOREDIR/scripts/get_field.sh configured incname`
libname=`$ROOTCOREDIR/scripts/get_field.sh configured libname`

if test "${bindir:0:1}" == "%"
then
    bindir=`pwd | xargs dirname`${bindir:1}
fi
if test "${incdir:0:1}" == "%"
then
    incdir=`pwd | xargs dirname`${incdir:1}
fi
if test "${libdir:0:1}" == "%"
then
    libdir=`pwd | xargs dirname`${libdir:1}
fi

if test "$bindir" != "" -a  "$binname" != ""
then
    for bin in "$bindir/"$binname
    do
	ln -sf $bin $ROOTCOREBIN/bin/ || exit $?
    done
fi
if test "$incdir" != ""
then
    for inc in $incname
    do
	rm -f $ROOTCOREBIN/include/$inc
	ln -sf $incdir/$inc $ROOTCOREBIN/include/$inc || exit $?
    done
fi
if test "$libdir" != ""
then
    for mylib in $libname
    do
	ln -sf $libdir/$mylib* $ROOTCOREBIN/lib/ || exit $?
	cd $ROOTCOREBIN/lib
	for lib in `ls | grep -E -e \\.dylib$`
	do
	    newlib=`echo $lib | grep $mylib | sed 's/\.dylib$/.so/'`
	    test \! -e $newlib && ln -s $lib $newlib
	done
	for lib in `ls | grep -E -e '-[0-9.]*\.'`
	do
	    newlib=`echo $lib | grep $mylib | sed 's/-[0-9.]*\././'`
	    test \! -e $newlib && ln -s $lib $newlib
	done
    done
fi

true
