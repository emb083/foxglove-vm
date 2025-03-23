#!/usr/bin/env bash

globalvar="this is global"

hello(){
    # keyword local for local variables
    local localvar="this is local"
    local globalvar="shadowing the global var"

    echo "localvar: $localvar"
    echo "globalvar (in hello()): $globalvar"
}

hello
echo "globalvar (outside func): $globalvar"