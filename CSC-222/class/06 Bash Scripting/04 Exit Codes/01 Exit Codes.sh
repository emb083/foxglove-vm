#!/usr/bin/env bash

# The $? variable

# Typically we use 0 for success
# Values 1-255 for various forms of error
# There are commonly used error codes. Examples:
#   127 - command not found
#   128 - invalid exit argument

# man [command] might tell you some of the error codes
# otherwise, internet

# Example:
echo "Last exit code: $?"
echo

echo "Example with ls -a"
ls -a
echo "Exit code: $?"
echo

echo "Example with nonsense"
notacommand -abcd
echo "Exit code: $?"
echo

echo "A way of error handling"
ls notrealdir   # intentionally a fake directory
if [ $? -gt 0 ]
then
    echo "Handled Error"
else
    echo "ls executed successfully"
fi
echo