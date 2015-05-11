#!/bin/sh

foo() {
    echo "function foo is executing"
}

echo "script start"
foo
echo "script end"

exit 0
