#!/usr/bin/env bash

# traditional for-loop
for (( i=0; i<5; i++ ))
do
    echo "Counter: $i"
done
echo

# for-each
for i in 1 2 3 4 5
do
    echo "Value: $i"
done
echo

# a range of values
for i in {0..5}
do
    echo "Range: $i"
done
echo

# incrementing more than 1 in a range
for i in {0..10..2}
do
    echo "Increment: $i"
done
echo