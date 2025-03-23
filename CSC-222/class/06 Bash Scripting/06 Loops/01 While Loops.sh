#!/usr/bin/env bash

# Format is:
# while [condition]
# do
#   contents
# done

# Example: counting up
counter=0
while [ $counter -le 10 ]
do
    printf "$counter"
    ((counter++)) # can do counter++ , ++counter , counter+=1 , or counter=$((counter+1))
    sleep 0.25
done
echo