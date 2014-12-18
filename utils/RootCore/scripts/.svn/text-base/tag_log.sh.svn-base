#!/bin/bash

set -e

url="$1"

if test "$url" == ""
then
    echo no url provided
    exit 1
fi


if test "`echo "$url" | grep '^atlas'`" != ""
then
    url="svn+ssh://svn.cern.ch/reps/$url"
fi

if test "x$CERN_USER" != "x"
then
    url=`echo "$url" | sed "s/svn+ssh:\/\/svn.cern.ch/svn+ssh:\/\/${CERN_USER}@svn.cern.ch/"`
fi

if test "`basename "$url"`" != "tags"
then
    url="$url/tags"
fi



for tag in `$ROOTCOREDIR/scripts/svn_retry.sh ls $url | sort -r`
do
    echo
    echo $tag | sed 's/\/$//'
    $ROOTCOREDIR/scripts/svn_retry.sh log --stop-on-copy "$url/$tag"
done
true
