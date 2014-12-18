#!/bin/bash

# this scripts copies an individual package into the grid distribution.

NOBUILD=
NOGRID=
done=0
while test $done -eq 0
do
    if test "$1" == "--nobuild"
    then
	NOBUILD=--nobuild
	shift
    elif test "$1" == "--nogrid"
    then
	NOGRID=--nogrid
	shift
    else
	done=1
    fi
done

test \! -d "$1" && echo could not find target $1 && exit 1
test \! -d "$2" && echo could not find package $2 && exit 2
PACKAGE=`basename $2`
test -d "$1/$PACKAGE" && echo package already copied && exit 3

EXCLUDES=""
if test "$PACKAGE" == "RootCore"
then
    EXCLUDES='--exclude include/\* --exclude python/\* --exclude user_scripts/\* --exclude data/\* --exclude lib/\* --exclude bin/\* --exclude grid_packages --exclude packages'
elif test "$NOBUILD" == ""
then
    EXCLUDES='--exclude StandAlone --exclude obj --exclude bin --exclude test-bin'
else
    EXCLUDES='--exclude obj'
fi

EXCLUDES="$EXCLUDES --exclude .svn --exclude \*~ --exclude \*.d --exclude \*.par"
if test "$NOBUILD" == ""
then
    EXCLUDES="$EXCLUDES --exclude \*.o --exclude \*.so --exclude \*.dylib"

    for clean in `$ROOTCOREDIR/scripts/get_field.sh $2/cmt/Makefile.RootCore PACKAGE_CLEAN`
    do
	EXCLUDES="$EXCLUDES --exclude $clean"
    done
fi
if test "$NOGRID" == ""
then
    for exclude in `$ROOTCOREDIR/scripts/get_field.sh $2/cmt/Makefile.RootCore PACKAGE_NOGRID`
    do
	EXCLUDES="$EXCLUDES --exclude $exclude"
    done
fi

eval rsync -a $EXCLUDES $2/. $1/$PACKAGE
