#!/bin/sh
set -x
cleanother(){
RMOBJ="*.pro.user *.Debug *.Release Makefile .qmake.stash debug release"
find . -type d -name "build*-Debug" | xargs rm -fr
for obj in $RMOBJ
do
	find . -type d -name "$obj" | xargs rm -fr 
done
}
cleanother
git add *
git commit -m "`date` push $1"
git push lhx main

