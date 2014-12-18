#!/bin/bash

source "`dirname $0`/preamble.sh" "$0"

set -e
set -u

continue=0
failure=0
make_flags=""
while test $# -gt 0
do
    if test "$1" == "--continue"
    then
	make_flags="$make_flags -k"
	continue=1
	shift
    else
	break
    fi
done

if test $# -ne 1
then
    echo invalid arguments for $0: $*
    exit 1
fi

pkg=$1
shift

if test \! -z "${ROOTCORE_NCPUS:+x}"
then
    make_flags="$make_flags -j $ROOTCORE_NCPUS"
fi

name=`basename $pkg`
echo compiling $pkg
if cd $pkg/cmt
then
    true
else
    echo "failed to enter package $pkg"
    exit 2
fi

if test -f precompile.RootCore
then
    if test \! -x precompile.RootCore
    then
	echo execute flag not set on precompile.RootCore, please run
	echo   chmod +x $pkg/cmt/precompile.RootCore
	exit 1
    fi
    if ./precompile.RootCore
    then
	true
    else
	echo failed to precompile package $pkg
	exit 1
    fi
fi

if make $make_flags -f Makefile.RootCore
then
    true
else
    echo "failed to compile package $pkg"
    if test $continue -eq 0
    then
	exit 1
    fi
    failure=1
fi
$ROOTCOREDIR/scripts/link_package.sh $pkg

test "`$ROOTCOREDIR/scripts/get_field.sh $pkg/cmt/Makefile.RootCore PACKAGE_NOCC`" != "1" && \
    echo $pkg | sed 's/.*\///' >>$ROOTCOREBIN/load
for lib in `$ROOTCOREDIR/scripts/get_field.sh Makefile.RootCore PACKAGE_PRELOAD`
do
    echo lib$lib >>$ROOTCOREBIN/preload
done

exit $failure
