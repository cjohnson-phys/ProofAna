#!/bin/bash

source "`dirname $0`/preamble.sh" "$0"

set -e

arguments=""
end=0
while test $end -ne 1
do
    if test "$1" == "-u"
    then
	arguments="$arguments -u"
	shift
    else
	end=1
    fi
done

for pkg in $ROOTCOREDIR `cat $pkgfile`
do
    echo $pkg:
    cd $pkg
    if test -d .svn
    then
	$ROOTCOREDIR/scripts/svn_retry.sh status $arguments | grep -E -v '^\? +([0-9]+ +)?StandAlone$' | grep -E -v '^\? +([0-9]+ +)?obj$' | grep -E -v '^\? +([0-9]+ +)?bin$' | grep -E -v '^\? +([0-9]+ +)?test-bin$' || true
    else
	echo '   not in SVN'
    fi
done
