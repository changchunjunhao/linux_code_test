#! /bin/sh

salutation="Hello"
echo $salutation
echo "The program $0(\$0) is now running"
echo "The first parameter was $1(\$1)"
echo "The second parameter was $2(\$2)"
echo "The parameter list was $*(\$*)"
echo "Another way $@(\$@)"
echo "The user's home directory is $HOME(\$HOME)"

echo exit
exit 0
