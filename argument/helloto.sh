#!/bin/bash


echo "Mr.$1 you are the first guest"
for name in $*
do
  echo "hello Mr.$name"
done
exit 0
