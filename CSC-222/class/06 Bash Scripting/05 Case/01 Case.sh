#!/usr/bin/env bash

echo "What is your favorite food? "
echo "1 - Pizza"
echo "2 - Ramen"
echo "3 - Pasta"

read food;

case $food in
    1) echo "Pizza is a great choice!";;    # The ;; marks the end of a case block
    2) echo "Ramen, a college classic."
       echo "Maruchan ain't too bad."
       ;;
    3) echo "Pastaaaaaaaaaaaaaaaaaa";;
    *) echo "Did I ask?";;
esac    # case backwards -_-