# Datastructures

This folder contains sample implementations for several common data types.

## Fields / Arrays / Queues / Stacks

- [array](array)
Dynamic array implementation in C.

- [intarray](intarray)
Dynamic array implementation in C - same as in [array](array), just for `int` instead of `char`.

- [linkedlist](linkedlist)
Linked list implemented in C, where each element knows it's successor, plus special _head_ and _tail_ elements.
(A double linked list is part of an exercise...).

- [queue](queue)
A FIFO queue implemented in C++ build on top of a LinkedList.

- [stack](stack)
A LIFO stack implemented in C++ build on top of a LinkedList.

- [dynarray](dynarray)
An array implementation in C++. Is a wrapper around std::vector<>, will be used for demonstrating search and sort algorithms.
This is not more "dynamic" than the array above, but "array" as name was already used for the C implementation ;)

## Trees

- [treearray](treearray)
Binary tree implemtation in C, based on an internal array.

The following classes are implemented as C++ _Template_. 
This allows each container class to contain arbitrary data types.
Due to the nature of templates, they have to be implemented in the header files.

- [bintree](bintree)
Simple binary tree implementation. You need to take care for adding elements yourself by using `addLeft(T)` or `addRight(T)`.
Again, because of being a template, this class already defines most of the functions we will need in the derived classes below, e.g. `insert()` or `balancedInsert(T)` as `dynamic_cast` otherwise is tricky.

- [binsearchtree](binsearchtree)
Binary Search Tree, derives `bintree` and implements an `insert` function.

- [bintreearray](bintreearray)
Binary tree implementation in C++ based on an array to store data.

## Tests

- [tests](tests)
Contains Google Test cases for some data structures.
Examples how to write Unit test for own data structures.

## Others

- [stackdemo.c](stackdemo.c)
Simple C function to demonstrate how C internally stores local variables on stack. 
Compile and disassemble, e.g. with gdb: `gdb bin/c02/stackdemo`
```
break main
break add
run
disassemble
```
