#!/bin/bash
echo "Running Google Test for all files in $1"
for i in $(find $1 -type f | sort)
do
  echo "Running $1"
  $1
  if [ $? -ne 0 ]
  then
    echo "Google Test detected issues."
    exit 1
  fi
done