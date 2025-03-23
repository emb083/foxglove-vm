#!/usr/bin/env bash

# Set the exit flag to cause the program to stop when it encounters an error

set -e

echo "This should print"
ls notrealdir
echo "this won't print"