#!/usr/bin/env bash

# read with -p will prompt for info
read -p "Enter your first and last name: " first last

# use -s for a secret (like a password)
echo "Give me a secret: "
read -s secret  # secret is the variable name, as the prompt is above

echo var first is $first
echo var last is $last
echo var secret is $secret