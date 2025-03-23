#!/usr/bin/env bash

# comment these filename variables in/out as needed
# filename="hello world.txt"
filename="04 File Testing.sh"
# filename="test directory"

# -e    checks if a file or directory exists with the given name
printf "File/Directory Existence: "
[[ -e $filename ]] && echo "True" || echo "False"

# -f    checks if the string matches a regular file (i.e. not a directory, or device)
printf "Actual File Exists: "
[[ -f $filename ]] && echo "True" || echo "False"

# -r    checks if it is readable
printf "File is readable: "
[[ -r $filename ]] && echo "True" || echo "False"

# -d    checks if it is a directory
printf "Is directory: "
[[ -d $filename ]] && echo "True" || echo "False"

# -L    checks if it is a symbolic link, or "shortcut"
printf "Is symbolic link: "
[[ -L $filename ]] && echo "True" || echo "False"

# -x    checks if it is an executable
printf "Is executable: "
[[ -x $filename ]] && echo "True" || echo "False"

# This is not an exhaustive list of things you can check with files