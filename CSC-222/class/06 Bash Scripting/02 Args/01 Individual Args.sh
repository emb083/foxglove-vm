#!/usr/bin/env bash

# User the $ followed by a number to access args passed into this script

echo The file name is $0
echo The arg at index 1 is $1
echo The arg at index 2 is $2

# The length of args can be found with the #
echo The length of the arg at index 1 is ${#1}