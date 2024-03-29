## This will link the linkedlist from snippets/02_datastructures
add_executable(queue_test_snp queue.cpp queue_test.cpp ../linkedlist/linkedlist.c)

## This will link the linkedlist from chapter/02_datastructures
#add_executable(queue_test_snp queue.cpp queue_test.cpp)
#target_link_libraries(queue_test queue linkedlist)