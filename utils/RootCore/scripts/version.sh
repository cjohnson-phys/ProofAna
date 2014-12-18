#!/bin/bash

source "`dirname $0`/preamble.sh" "$0"

for pkg in $ROOTCOREDIR `cat $pkgfile`
do
    if test \! -d $pkg/.svn
    then
	echo `basename $pkg` not in SVN
    else
	url=`svn info $pkg | grep ^URL | awk ' { print $2 } ' | sed 's/^svn+ssh:\/\/.*svn.cern.ch\/reps\/atlas/atlas/'`
	if test "$url" != ""
	then
	    echo $url
	else
	    echo `basename $pkg` in SVN, but can\'t extract URL
	fi
    fi
done
