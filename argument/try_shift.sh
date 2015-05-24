#!/bin/bash

if [ "$#" -lt 2 ];then
	echo "num of param should be 2 at least"
	exit 1
fi

echo "num1 is $1"
echo "\$# is $# now"

shift
echo "after shift"

echo "num1 is $1"
echo "\$# is $# now"
