#!/bin/bash

## Debug out
find /app
#ls -alF /app/bin

#!/bin/bash
echo "Running all files in /app/bin"
for i in $(find /app/bin -executable -type f | sort | grep -v _input | grep -v boost | grep -v .sh)
do
  echo "####################################################################"
  echo "Executing $i"
  echo "####################################################################"
  $i
done