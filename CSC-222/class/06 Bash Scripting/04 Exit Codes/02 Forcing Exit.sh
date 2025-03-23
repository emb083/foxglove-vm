#!/usr/bin/env bash

read -p "What file would you like to remove? " filename
if [ ! -f $filename ]
then
    echo "That file does not exist... exiting"
    exit 1
fi

rm $filename && echo "File successfully removed"