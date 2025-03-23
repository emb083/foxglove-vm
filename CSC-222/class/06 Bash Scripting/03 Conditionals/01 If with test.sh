#!/usr/bin/env bash

# using the keyword test with an if statement
if test $1 -gt 5    # if arg1 is greater than 5
then
    echo "x is greater than 5"  # indentation is reccomended for style, but not required
fi

if test $1 -gt 5
then
    echo "greater than"
else
    echo "lesser than"
fi