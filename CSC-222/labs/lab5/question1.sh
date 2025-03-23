#!/usr/bin/env bash

eA() {
    # euclidean algorithm
    result=0
    a=$1
    b=$2
    if [ $a -eq 0 ]; then
        result=$b
    elif [ $b -eq 0 ]; then
        result=$a
    else
        while [ $b -gt 0 ]
        do
            remainder=$((a % b))
            a=$b
            b=$remainder
        done
        result=$a
    fi

    echo $result
    return
}

if [[ $# -lt 2 || $# -gt 2 ]]
then
    echo "Usage: ./question1 <int> <int>"
else
    gcd=$(eA $1 $2)
    echo "The GCD of $1 and $2 is $gcd"
fi