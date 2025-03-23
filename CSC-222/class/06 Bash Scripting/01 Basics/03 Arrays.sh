#!/usr/bin/env bash

# Declaring and assigning values for arrays
# Use parantheses and space separation for each item

groceries=("bread" "milk" "eggs")
costs=(1 10 23.99)

# accessing the values
echo $groceries         # only prints first item
echo $groceries[0]      # prints bread[0]
echo ${grocieres[1]}    # gets the second item
echo

echo ${costs[0]} ${costs[1]} ${costs[2]}
echo ${costs[@]}    # @ as index gets all the values
echo

printf "Food item: ${groceries[1]}\t\tPrice: ${costs[1]}\n"
printf "Food item: %s\t\tPrice: %d\n" ${groceries[1]} ${costs[1]}
echo

# Just declaring and assigning values later
# does not work in zsh

# Numeric array - index is in a numeric form
declare -a numeric_array    # use lowercase a flag

numeric_array[0]="Hello"    # setting values
numeric_array[1]="World"
numeric_array+=("Hello Elia")   # appending values
echo ${numeric_array[@]}
echo

# Associative arrays - the index is a named value (like a key in a dictionary)
# this only exists in bash v4+
# no order to these
declare -A asc_array    # use capital a flag for associative arrays

asc_array[first]="Liam"
asc_array[middle]="Sage"
asc_array[last]="Hargrove"
echo Values: ${asc_array[@]}
echo Keys: ${!asc_array[@]}
echo