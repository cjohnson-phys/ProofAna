#!/bin/bash

set -e
source "`dirname $0`/preamble.sh" "$0"

action=$1
list=$2
opt=""

if test "$action" != "checkout" -a -f "$pkgfile"
then
    for package in "$ROOTCOREDIR" `cat $pkgfile`
    do
	$ROOTCOREDIR/scripts/manage_pkg.sh "$action" "" "$package" "$list"
    done
    opt=second
fi

if test "$action" != "update" -a "$list" != ""
then
    if test \! -f "$list"
    then
	echo "did not find list file $list"
	false
    fi
    for url in `grep -v '^#' $list`
    do
	$ROOTCOREDIR/scripts/manage_pkg.sh "$action" "$url" "" "$list" "$opt"
    done
fi
true
