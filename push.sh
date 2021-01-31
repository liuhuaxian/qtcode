#!/bin/sh
set -x
if [[ $1 != '' ]]
then
	cd $1
	rm *.pro.user *.Debug *.Release Makefile .qmake.stash debug release -fr
	cd ..
fi
rm *MinGW_32bit-Debug -fr
git add *
git commit -m "`date` push $1"
git push lhx main

