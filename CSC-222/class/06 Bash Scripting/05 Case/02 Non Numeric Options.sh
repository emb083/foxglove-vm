#!/usr/bin/env bash

printf "What do you drive? "
read vehicle

case $vehicle in
    car)
        echo "You drive a car."
        echo "Is there a car directory in this folder?"
        if [[ -d "car" ]]
        then
            echo "There is!"
        else
            echo "Nope."
        fi
        ;;
    truck)
        echo "You drive a truck?"
        echo "Bet you think you're special."
        ;;
    van)
        echo "Perfect to carry all the Non-GMO soccer fiends you spawned."
        ;;
    *)
        echo "What's a make? I only know car/truck/van"
        ;;
esac