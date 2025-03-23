#!/usr/bin/env bash

# [ ] is a shorthand for test

if [ $1 -lt 10 ]    # spacing around contents is REQUIRED
then
    echo "$1 is less than 10"
elif [ $1 -gt 10 ]
then
    echo "$1 is greater than 10"
else
    echo "$1 is equal to 10"
fi