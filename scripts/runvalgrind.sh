#!/bin/bash
echo "Running valgrind for all files in $1"
for i in $(find $1 -type f | sort | grep -v _input | grep -v _benchmark)
do 
  valgrind --track-origins=yes --leak-check=full --error-exitcode=1 --exit-on-first-error=yes $i
  if [ $? -ne 0 ]
  then
    echo "Valgrind detected memory leak"
    exit 1
  fi
done