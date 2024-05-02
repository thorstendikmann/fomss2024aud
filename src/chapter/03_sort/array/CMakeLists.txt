add_library(array_swap swap.c)
set_target_properties(array_swap PROPERTIES PUBLIC_HEADER "swap.h")
install(TARGETS array_swap PUBLIC_HEADER DESTINATION include/array)

add_library(array_unsort unsort.c)
target_link_libraries(array_unsort array_swap)
set_target_properties(array_unsort PROPERTIES PUBLIC_HEADER "unsort.h")
install(TARGETS array_unsort PUBLIC_HEADER DESTINATION include/array)

add_library(array_selectionsort selectionsort.c)
target_link_libraries(array_selectionsort array_swap)
set_target_properties(array_selectionsort PROPERTIES PUBLIC_HEADER "selectionsort.h")
install(TARGETS array_selectionsort PUBLIC_HEADER DESTINATION include/array)

add_library(array_bubblesort bubblesort.c)
target_link_libraries(array_bubblesort array_swap)
set_target_properties(array_bubblesort PROPERTIES PUBLIC_HEADER "bubblesort.h")
install(TARGETS array_bubblesort PUBLIC_HEADER DESTINATION include/array)

add_library(array_insertionsort insertionsort.c)
target_link_libraries(array_insertionsort array_swap)
set_target_properties(array_insertionsort PROPERTIES PUBLIC_HEADER "insertionsort.h")
install(TARGETS array_insertionsort PUBLIC_HEADER DESTINATION include/array)

add_library(array_insertionsortinplace insertionsortinplace.c)
target_link_libraries(array_insertionsortinplace array_swap)
set_target_properties(array_insertionsortinplace PROPERTIES PUBLIC_HEADER "insertionsortinplace.h")
install(TARGETS array_insertionsortinplace PUBLIC_HEADER DESTINATION include/array)

add_library(array_mergesort mergesort.c)
target_link_libraries(array_mergesort array_swap)
set_target_properties(array_mergesort PROPERTIES PUBLIC_HEADER "mergesort.h")
install(TARGETS array_mergesort PUBLIC_HEADER DESTINATION include/array)

add_library(array_quicksort quicksort.c)
target_link_libraries(array_quicksort array_swap)
set_target_properties(array_quicksort PROPERTIES PUBLIC_HEADER "quicksort.h")
install(TARGETS array_quicksort PUBLIC_HEADER DESTINATION include/array)

add_library(array_heapsort heapsort.c)
target_link_libraries(array_heapsort array_swap)
set_target_properties(array_heapsort PROPERTIES PUBLIC_HEADER "heapsort.h")
install(TARGETS array_heapsort PUBLIC_HEADER DESTINATION include/array)

add_executable(array_sort_test array_sort_test.c)
target_link_libraries(array_sort_test
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
install(TARGETS array_sort_test DESTINATION bin/c03)

add_executable(array_sort_exercise_elem array_sort_exercise_elem.c)
target_link_libraries(array_sort_exercise_elem
    intarray
    array_selectionsort
    array_bubblesort
    array_insertionsortinplace
)
install(TARGETS array_sort_exercise_elem DESTINATION bin/c03)

add_executable(array_sort_test_mergesort array_sort_test_mergesort.c)
target_link_libraries(array_sort_test_mergesort
    intarray
    array_mergesort
)
install(TARGETS array_sort_test_mergesort DESTINATION bin/c03)

add_executable(array_sort_test_quicksort array_sort_test_quicksort.c)
target_link_libraries(array_sort_test_quicksort
    intarray
    array_quicksort
)
install(TARGETS array_sort_test_quicksort DESTINATION bin/c03)

add_executable(array_sort_test_heapsort array_sort_test_heapsort.c)
target_link_libraries(array_sort_test_heapsort
    intarray
    array_heapsort
)
install(TARGETS array_sort_test DESTINATION bin/c03)
