#!/usr/bin/env bash

# Operations with integers are supported, and that's all
# Notation $((num1 + num2))

echo $((3+2))
echo $((3-2))
echo $((3*2))
echo $((3/2))
echo $((3%2))
echo

# Non-integers can be piped into bc (basic calculator)
echo "2.3 + 1.2" | bc
echo "scale=5; 10/3" | bc   # scale specifies decimals
echo "sqrt(12)" | bc -l     # imports math library