#!/usr/bin/env bash

# Preferred Way for Bash
# preferred since the function keyword exists in bash

function hello_one {
    echo "Hello!"
    echo "Done."
}

# More Portable Way
# the 'function' keyword isn't POSIX compliant
# (Portable Operating System Interface for unix-like systems)

hello_two(){
    echo "Hello again!"
    echo "Done."
}

hello_one
hello_one
hello_two