# Sorting

This folder contains implementations of different "traditional" sorting algorithms.

## Elementary sort algorithms

"Elementary" sort algorithms usually have a complexity of $O(n^2)$.

- [array](array)
Implementation of elementary sort algorithms, one in an separate each file, e.g.
  - [selectionsort](array/selectionsort.h)
  - [insertionsort](array/insertionsort.h)
  - [bubblesort](array/bubblesort.h)

Plus additional supplementary functions:
- [array](array)
  - [swap](array/swap.h) - triangular swap of two array items
  - [unsort](array/unsort.h) - helper to randomize array ... the "un"sort algorithm :)

## Asymptotically optimal sort algorithms

"Optimal" sort algorithms have a complexity usually of $O(n\cdot \log(n))$.

- [array](array)
Implementation of asymptotically optimal sort algorithms, one in an separate each file, e.g.
  - [mergesort](array/mergesort.h)
  - [quicksort](array/quicksort.h)
  - [heapsort](array/heapsort.h)

## Other sort algorithms

Implementation of other, non-comparing sort algorithms.

- [bucketsortarray](bucketsortarray/bucketsortarray.h) - Bucketsort, implemented in C++ , derived from <tt>Array&lt;double&gt;</tt> (see [dynarray](../02_datastructures/dynarray) )
- [countingsortarray](countingsortarray/countingsortarray.h) - Countingsort, implemented in C++ , derived from <tt>Array&lt;unsigned int&gt;</tt> (see [dynarray](../02_datastructures/dynarray) )
- [radixsortarray](radixsortarray/radixsortarray.h) - Radixsort, implemented in C++ , derived from <tt>Array&lt;unsigned int&gt;</tt> (see [dynarray](../02_datastructures/dynarray) ). Based on Bucketsort.