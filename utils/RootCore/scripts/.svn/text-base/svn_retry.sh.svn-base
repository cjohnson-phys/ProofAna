#!/bin/bash

if test "$TMPDIR" == ""
then
    TMPDIR=/tmp/
fi

if test "$1" == "update"
then
    svn "$@" || svn "$@" || svn "$@"
    exit $?
else
    FILE=$TMPDIR/svn-out.$$
    if svn "$@" >$FILE || svn "$@" >$FILE || svn "$@" >$FILE
    then
	cat $FILE
	rm -f $FILE
    else
	result=$?
	cat $FILE
	rm -f $FILE
	exit $result
    fi
fi

