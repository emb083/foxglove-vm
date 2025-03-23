#!/bin/bash

# the above line is an absolute path to the bash interpreter of your choosing
# it is known as the shebang

# To use the most recent version of bash on your machine:
#!usr/bin/env bash

# If you have zsh:
#!/bin/zsh

# To run this file, we need to give it permissions to execute

# Print a simple statement
echo Hello, world!

# back tick to use commands
echo I am `whoami`
echo Today: `date`
echo Working directory: `pwd`

# can use printf
printf hi   # there is no default newline character like echo
printf "Same line as previous\n"
printf "Different line\n"

printf "Today: `date`\n" # backticks still work inside printf