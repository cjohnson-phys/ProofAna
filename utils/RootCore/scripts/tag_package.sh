#!/bin/bash

set -e
set -u

batch=0
while test $# -gt 1
do
    if test "$1" == "--batch"
    then
	batch=1
	shift
    else
	break
    fi
done

if test $# -ne 1
then
    echo invalid number of arguments for tag_package
    exit 1
fi

message=$1
if test "$message" = ""
then
    echo no message given
    exit 1
fi

echo message begin
echo "$message"
echo message end

url=`svn info . | grep ^URL | awk ' { print $2 } '`
if test "`basename $url`" != "trunk"
then
    echo not in the head of the package
    if test "`dirname $url | xargs basename`" == "tags"
    then
	url=`dirname $url | xargs dirname`/trunk
    else
	echo don\'t know how to handle url: $url
	exit 1
    fi
    if test $batch -eq 0
    then
	echo -n "please confirm changing to trunk (answer yes): "
	read var
	if test "$var" != "yes"
	then
	    echo aborting
	    exit 1
	fi
    fi
    svn switch $url
fi
url=`dirname $url`

# rationale: putting this here to give you an option to check while
#   reading tags from the server
$ROOTCOREDIR/scripts/svn_retry.sh update
svn status

version=`$ROOTCOREDIR/scripts/svn_retry.sh ls $url/tags | tail -n 1 | sed 's/\/$//' | sed 's/^[^-]*-//' | sed 's/-//g'`
if test "$version" = ""
then
    version=0
fi
version=`expr $version + 1`
while test `echo $version | wc | awk ' { print $3 } '` -lt 7
do
    version=0$version
done
tag=`basename $url`-${version:0:2}-${version:2:2}-${version:4:2}


if test "`svn status`" != ""
then
    if test $batch -eq 0
    then
	echo -n "please confirm committing changes (answer yes): "
	read var
	if test "$var" != "yes"
	then
	    echo aborting
	    exit 1
	fi
    fi
    if $ROOTCOREDIR/scripts/svn_retry.sh commit -m "$message"
    then
	true
    else
	echo failed to commit
	exit 1
    fi
fi


if test $batch -eq 0
then
    echo -n "please confirm creating tag $tag (answer yes): "
    read var
    if test "$var" != "yes"
    then
	echo aborting
	exit 1
    fi
fi

if $ROOTCOREDIR/scripts/svn_retry.sh cp -m "$message" $url/trunk $url/tags/$tag
then
    echo made tag $tag
else
    echo failed to create tag
    exit 1
fi
