#!/bin/sh
# this tests a bug in handling of - chars in Unlabeled args
# success  
`dirname $0`/simple-test.sh `basename $0 .sh` test2 -i 10 -s hello "-1 -1"
