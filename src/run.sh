#!/bin/bash

## Debug out
#find /src
#find /app

### Hello World

/app/bin/hello_world_c
/app/bin/hello_world_cpp

PYHTON3=/usr/bin/python3
${PYHTON3} /tmp/app/src/hellopython/helloworld.py

## Tests
/app/test/test_helloworld
/app/test/test_somefunctions