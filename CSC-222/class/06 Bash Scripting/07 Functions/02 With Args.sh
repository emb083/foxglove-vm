#!/usr/bin/env bash

hello(){
    echo "Hello, $1!"
}

add(){
    printf "The sum of $1 and $2 is "
    echo $(( $1 + $2 ))
}

helloEveryone(){
    echo "Hello, $@!" # accesses all of the arguments
}

# arguments are space separated when calling the function
hello "Josh"
add 5 10
helloEveryone Sage Danison Gage Garrett Cooper