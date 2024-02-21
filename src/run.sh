#!/bin/bash

## Debug out
find /app
#ls -alF /app/bin

## Hello World
if [ -d /app/bin/hello/ ]
then
    /app/bin/hello/hello_world_c
    /app/bin/hello/hello_world_cpp
fi

if [ -f /app/src/helloworlds/hellopython/helloworld.py ]
then
    PYHTON3=/usr/bin/python3
    ${PYHTON3} /app/src/helloworlds/hellopython/helloworld.py
else
    echo "No python files found."
fi

## Tests
if [ -d /app/test ]
then
    /app/test/test_helloworld
    /app/test/test_somefunctions
else
    echo "No test files found."
fi

## Boost
if [ -f /app/bin/helloboost ]
then
    /app/bin/hello/helloboost
fi

## ASM & Qemu
if [[ "`uname -m`" == "x86_64" ]]
then
    echo "Architecture: x86_64"
    if [ -f /app/bin/hello/hello_world_asm ]
    then
        /app/bin/hello/hello_world_asm
    fi
elif [[ "`uname -m`" == "arm" ]]
then
    echo "Architecture: arm"
fi

## Chapter 00
if [ -d /app/bin/c00 ]
then
    /app/bin/c00/simplefunctions
    /app/bin/c00/input
    /app/bin/c00/structs
    /app/bin/c00/arrays
    /app/bin/c00/fahrenheit
    valgrind -q --leak-check=full -s /app/bin/c00/00_pointer

    /app/bin/c00/cpp_simplefunctions
    /app/bin/c00/cpp_classes
    /app/bin/c00/cpp_namespaces
fi

## Exercises 01
if [ -d /app/bin/u01 ]
then
    /app/bin/u01/datum
    /app/bin/u01/rechteck
    /app/bin/u01/eingabe
    /app/bin/u01/algorithmen
fi