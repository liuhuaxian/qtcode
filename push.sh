#!/bin/sh
set -x
git add *
git commit -m "`date`"
git push lhx main

