#!/usr/bin/env bash

multAll() {
    args=$#
    result=1
    for i in $@; do
        result=$((result * i))
    done
    echo $result
    return
}

if [ $# -gt 0 ]; then
    product=$(multAll $@)
    echo "The product of $* is $product"
else
    echo "Usage: ./question2 <int> <int> <int> ..."
fi