#!/bin/sh
set -x
cleanother(){
cd $1
RMOBJ="*.pro.user *.Debug *.Release Makefile .qmake.stash debug release"
find . -type d -name "build*-Debug" | xargs rm -fr
for obj in $RMOBJ
do
	find . -type d -name "$obj" | xargs rm -fr 
done
cd ..
}

if [[ $1 != '' ]]
then
	cleanother $1
fi
rm *MinGW_32bit-Debug -fr
git add *
git commit -m "`date` push $1"
git push lhx main

