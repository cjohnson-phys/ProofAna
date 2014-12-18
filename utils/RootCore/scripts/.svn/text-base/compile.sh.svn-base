#!/bin/bash

source "`dirname $0`/preamble.sh" "$0"

set -e
set -u

continue=0
log_files=0
compile_pkg_flags=""
log_file_redirect=""
while test $# -gt 0
do
    if test "$1" == "--continue"
    then
	compile_pkg_flags="--continue"
	continue=1
	shift
    elif test "$1" == "--log-files"
    then
	log_files=1
	log_file_redirect='>$log_file 2>&1'
	shift
    else
	break
    fi
done

if test $# -ne 0
then
    echo invalid arguments for $0: $*
    exit 1
fi



rm -rf $ROOTCOREBIN/bin
mkdir $ROOTCOREBIN/bin

# this is my way of creating the rc link without introducing race conditions
test -e $ROOTCOREBIN/bin/rc && test \! -f $ROOTCOREBIN/bin/rc && rm -f $ROOTCOREBIN/bin/rc || true
test -f $ROOTCOREBIN/bin/rc || ln -s $ROOTCOREDIR/scripts/rc.sh $ROOTCOREBIN/bin/rc || test -f $ROOTCOREBIN/bin/rc

rm -rf $ROOTCOREBIN/include
mkdir $ROOTCOREBIN/include
rm -rf $ROOTCOREBIN/python
mkdir $ROOTCOREBIN/python
rm -rf $ROOTCOREBIN/user_scripts
mkdir $ROOTCOREBIN/user_scripts
rm -rf $ROOTCOREBIN/data
mkdir $ROOTCOREBIN/data
rm -rf $ROOTCOREBIN/lib
mkdir $ROOTCOREBIN/lib

rm -f $ROOTCOREBIN/preload
touch $ROOTCOREBIN/preload
rm -f $ROOTCOREBIN/load
touch $ROOTCOREBIN/load

mkdir -p "$ROOTCOREBIN/RootCore"
file="$ROOTCOREBIN/RootCore/Packages.h"
rm -f "$file-"
echo '#ifndef ROOTCORE_PACKAGES_H' >"$file-"
echo '#define ROOTCORE_PACKAGES_H' >>"$file-"
echo >>"$file-"
echo '// This file contains one define statement for each package detected by' >>"$file-"
echo '// RootCore.  It is meant to allow to write package A in a form that' >>"$file-"
echo '// it uses the services of package B when available, but otherwise' >>"$file-"
echo '// skips it without failing.  For this to work properly you need to list' >>"$file-"
echo '// package B in the PACKAGE_TRYDEP of package A.' >>"$file-"
echo >>"$file-"
for pkg in RootCore `cat $pkgfile`
do
    echo "#define ROOTCORE_PACKAGE_`basename $pkg`" >>"$file-"
done
echo >>"$file-"
echo '#endif' >>"$file-"
if test -f "$file" && cmp --quiet "$file" "$file-"
then
    rm -f "$file-"
else
    cp -f "$file-" "$file"
fi
ln -s "$ROOTCOREBIN/RootCore" "$ROOTCOREBIN/include/RootCore"

failures=""
for pkg in `cat $pkgfile`
do
    if test $log_files -eq 1
    then
	log_file=`$ROOTCOREDIR/scripts/package_info.sh nicos_name $pkg`.loglog
	if test \! -z "${ROOTCORELOG:+x}"
	then
	    log_file=$ROOTCORELOG/$log_file
	fi
	echo writing `basename $pkg` compilation log to $log_file
    fi
    if eval \$ROOTCOREDIR/scripts/compile_pkg.sh \$compile_pkg_flags \$pkg $log_file_redirect
    then
	true
    else
	error=$?
	if test $continue -eq 0
	then
	    exit $error
	fi
	failures="$failures $pkg"
    fi
done

rm -f $ROOTCOREBIN/load_packages_success
if $ROOTCOREDIR/scripts/root.sh -l -b -q $ROOTCOREDIR/scripts/load_packages.C && test -f $ROOTCOREBIN/load_packages_success
then
    true
else
    echo "failed to test load libraries"
    exit 4
fi

if test "$failures" != ""
then
    echo compilation failures in: $failures
    exit 1
fi
true
