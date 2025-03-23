#!/usr/bin/env bash

# the return keyword is typically used to set the exit status
# echo is typically used to return a computed value from the function
# another option instead of echo is to set a global variable
add_one(){
    if [ -z $1 ]
    then
        return 1
    else
        echo $(( $1 + 1 ))
        return 0
    fi
}

echo "Example 1"
result=$(add_one 20)
exit_status=$?
if (( exit_status > 0 ))
then
    echo "an error occured"
else
    echo "The result was $result"
fi

echo "Example 2"
result=$(add_one)
exit_status=$?
if (( exit_status > 0 ))
then
    echo "an error occured"
else
    echo "The result was $result"
fi