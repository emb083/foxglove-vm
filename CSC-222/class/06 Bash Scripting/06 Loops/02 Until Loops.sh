#!/usr/bin/env bash


# Structure:
# until [condition]
# do
#   contents
# done

# Example:

until [ -f "hello.txt" ]
do
    echo "Let's make a file named 'hello.txt'\n"
    read -p "What would you like to name the file? " filename
    touch "$filename"
done
echo "Good job!"