## Directly add reference to linkedlist here
add_executable(queue_test_snp queue.cpp queue_test.cpp ../linkedlist/linkedlist.c)

## Or link linkedlist library
#add_executable(queue_test_snp queue.cpp queue_test.cpp ../linkedlist/linkedlist.c)
#target_link_libraries(queue_test queue linkedlist)