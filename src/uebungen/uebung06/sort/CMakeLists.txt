set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/u06)

add_executable(exercise_array_sort exercise_array_sort.c)
target_link_libraries(exercise_array_sort
    intarray
    array_unsort
    array_selectionsort
    array_bubblesort
    array_insertionsort
    array_insertionsortinplace
    array_mergesort
    array_quicksort
    array_heapsort
)
install(TARGETS exercise_array_sort DESTINATION bin/u06)