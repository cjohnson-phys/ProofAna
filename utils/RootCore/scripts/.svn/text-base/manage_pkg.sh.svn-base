#!/bin/bash

set -e
source "`dirname $0`/preamble.sh" "$0"

action=$1
url=$2
dir=$3
list=$4
opt=$5


function check_head {
    test "`basename "$1"`" = "trunk" && return 1
    test "`basename "$url"`" = "tags" && return 0
    test "`dirname "$url" | xargs basename`" = "tags" && return 0
    test "`dirname "$url" | xargs basename`" = "branches" && return 1
    return 1
}



if test "$dir" != ""
then
    name=`basename $dir`
elif test "$url" != ""
then
    if test "`basename "$url"`" = "trunk"
    then
	name=`dirname "$url" | xargs basename`
    elif test "`basename "$url"`" = "tags"
    then
	name=`dirname "$url" | xargs basename`
    elif test "`dirname "$url" | xargs basename`" = "tags"
    then
	name=`dirname "$url" | xargs dirname | xargs basename`
    elif test "`dirname "$url" | xargs basename`" = "branches"
    then
	name=`dirname "$url" | xargs dirname | xargs basename`
    else
	name=`basename "$url"`
    fi
else
    echo need to specify either a directory or a URL for a directory
    exit 1
fi



if test "$url" == "" -a "$list" != ""
then
    url=`grep -E "^[^#].*/$name(/|$)" "$list" || true`
fi

if test "$url" == "" -a -d "$dir/.svn"
then
    svnurl=`svn info $dir | grep ^URL | awk ' { print $2 } '`
    if test "$action" != "update" -o "`dirname $svnurl | xargs basename`" != "tags"
    then
	url="$svnurl"
    fi
fi



# this will fetch the right directory, except for checkout, which is
# always supposed to checkout to the local directory in order to make
# it easy to create new RootCore releases
if test "$action" != "checkout"
then
    if test "$name" == "RootCore"
    then
	dir="$ROOTCOREDIR"
    elif test "$dir" == "" -a -f "$pkgfile"
    then
	dir=`grep "/$name$" $pkgfile | grep -v "^#" ; true`
    fi
fi

if test "$dir" == ""
then
    dir=`pwd`/$name
fi



# this will skip packages from the package file for the second
# iteration over all packages
if test "$opt" == "second" -a -f "$pkgfile"
then
    if test "`echo $pkgfile | grep -E "^[^#].*/$name(/|;)"`" != ""
    then
	exit
    fi
fi



# these are quick aborts for when we do nothing, so that we will never
# query SVN for the full version
if test "$action" == "checkout"
then
    if test -d "$dir"
    then
	exit
    fi
elif test "$action" == "update"
then
    if test \! -d "$dir"
    then
	echo WARNING: skipping unknown package $name for update
	exit
    fi
fi



if test "`echo "$url" | grep '^atlas'`" != ""
then
    url="svn+ssh://svn.cern.ch/reps/$url"
fi

if test "x$CERN_USER" != "x"
then
    url=`echo "$url" | sed "s/svn+ssh:\/\/svn.cern.ch/svn+ssh:\/\/${CERN_USER}@svn.cern.ch/"`
fi

if test "`echo $url | grep svn.cern.ch`" != "" -a -d "$dir"
then
    url2="`svn info "$dir" | grep ^URL | awk ' { print $2 } '`"
    if test "`echo $url2 | grep svn.cern.ch`" != ""
    then
	url="`echo $url2 | sed 's/svn.cern.ch.*//'`svn.cern.ch`echo $url | sed 's/.*svn.cern.ch//'`"
    fi
fi

if test "`basename "$url"`" == "tags"
then
    # pick up the latest tag
    url="$url"/`$ROOTCOREDIR/scripts/svn_retry.sh ls "$url" | tail -n 1 | sed 's/\///'`
    # or if none is found, switch to the trunk version
    url=`echo "$url" | sed 's/tags\/$/trunk/'`
fi



if test "$action" == "build"
then
    if test -d "$dir"
    then
	action=update
    else
	action=checkout
    fi
fi



if test "$action" == "checkout"
then
    if test "$url" == ""
    then
	echo WARNING: no url for package $name, skipping
	exit
    fi
    parent=`dirname "$dir"`
    mkdir -p "$parent"
    cd "$parent"
    $ROOTCOREDIR/scripts/svn_retry.sh co "$url" $name
elif test "$action" == "update"
then
    if test "$url" == ""
    then
	echo WARNING: no url for package $name, skipping
	exit
    fi
    current=`svn info $dir | grep ^URL | awk ' { print $2 } '`

    if test "$url" == "$current"
    then
	if test "`dirname $url | xargs basename`" == "tags"
	then
	    echo package $name already at version `basename $url`
	    exit
	fi
	echo updating $name from head
	cd $dir
	$ROOTCOREDIR/scripts/svn_retry.sh update
    else
	if test "`cd $dir && svn status | grep -E ^[MC]`" != ""
	then
	    echo you currently have changes in package $name
	    echo either check them in, or switch versions manually using:
	    echo   cd $dir
	    echo   svn switch $url
	    exit
	fi
	cd $dir
	$ROOTCOREDIR/scripts/svn_retry.sh switch "$url"
    fi
else
    echo unknown action $action
    false
fi
