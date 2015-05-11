#!/bin/bash

#it is sensitive about the backspace
#if you write like this: 
#myvar = "Hi there"
#Or myvar= "Hi there"
#it will throw an error. Be caution!
myvar="Hi there"

echo $myvar
echo \$myvar
echo "$myvar"
echo '$myvar'

echo Enter some text
read myvar

echo '$myvar' now equals $myvar

exit 0
