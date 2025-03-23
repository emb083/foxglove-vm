#!/usr/bin/env bash

# Setting variables
# User the = symbol with NO SPACES around it

my_var=10
another_var="the variable is..."

# Accessing Variables
# The $ is used to access variable values
echo $another_var $my_var
echo The var is $my_var
echo

# Using quotes with echo to access the variable
echo "The var is $my_var"
echo 'The var is $my_var'   # will literally print my_var
echo

# Escaping
echo -e "Line1\nLine2"  # -e must be used to access some special characters
echo "Line1\nLine2"     # prints everything on one line
echo "The banana is \$$my_var"

printf "Hi \nhow are you\n"
printf "The banana is %d\n" $my_var