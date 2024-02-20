#!/bin/bash

## Debug out
find /app
#ls -alF /app/bin

## Hello World
/app/bin/hello_world_c
/app/bin/hello_world_cpp

if [ -f /app/src/hellopython/helloworld.py ]
then
    PYHTON3=/usr/bin/python3
    ${PYHTON3} /app/src/hellopython/helloworld.py
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

## ASM & Qemu
if [[ "`uname -m`" == "x86_64" ]]
then
    echo "Architecture: x86_64"
    if [ -f /app/bin/hello_world_asm ]
    then
        /app/bin/hello_world_asm
    fi
elif [[ "`uname -m`" == "arm" ]]
then
    echo "Architecture: arm"
fi

## Chapter 00
/app/bin/00_simplefunctions
#/app/bin/00_input
/app/bin/00_structs
/app/bin/00_arrays
valgrind -q --leak-check=full -s /app/bin/00_pointer

/app/bin/00_cpp_simplefunctions
/app/bin/00_cpp_classes
/app/bin/00_cpp_namespaces