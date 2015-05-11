#!/bin/sh

echo "Is it morning? Please answer yes or no"
read timeofday

if [ "$timeofday" = "yes" ]
then
    echo "good morning"
elif test "$timeofday" = "no"
then
    echo "good afternoon"
else
    echo "canot deal it"
    exit 1
fi

exit 0

#instead of $timeofday, "$timeofday" will make the system strong when the user just press Enter when reading timeofday. if[="yes"] is an error
