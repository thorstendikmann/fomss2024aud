#!/bin/bash
echo "Running valgrind for all files in $1"
for i in $(find $1 -executable -type f | sort | grep -v _input | grep -v _benchmark | grep -v boost | grep -v ".sh")
do
  echo "valgrind $i"
  valgrind --track-origins=yes --leak-check=full --error-exitcode=1 --exit-on-first-error=yes $i
  if [ $? -ne 0 ]
  then
    echo "Valgrind detected issues."
    exit 1
  fi
done