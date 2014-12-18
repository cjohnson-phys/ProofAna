#!/bin/bash

source "`dirname $0`/preamble.sh" "$0"

set -e
set -u

if test $# -ne 2
then
    echo invalid arguments for $0: $*
    exit 1
fi
cmd=$1
pkg=$2


if test "$cmd" == "nicos_name"
then
    if test -d "$pkg/.svn"
    then
	url="`svn info $pkg | grep URL | awk ' { print $2 } ' | sed 's/.*\/atlas/atlas/' | sed 's/^atlas[a-z]*\///'`"
    else
	url=`basename $pkg`
    fi
    if test `echo $url | wc -w` -ne 1
    then
	echo failed to extract url, read: $url
	exit 1
    fi
    if test "`basename $url`" == "trunk"
    then
	url=`dirname $url`
    elif test "`dirname $url | xargs basename`" == "tags"
    then
	url=`dirname $url | xargs dirname`
    elif test "`dirname $url | xargs basename`" == "branches"
    then
	url=`dirname $url | xargs dirname`
    fi
    echo $url | sed 's/\//_/g'
else
    echo unknown package info command: $cmd
fi
