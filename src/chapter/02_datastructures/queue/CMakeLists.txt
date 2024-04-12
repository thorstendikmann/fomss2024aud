add_library(queue queue.cpp)
target_link_libraries(queue linkedlist)
set_target_properties(queue PROPERTIES PUBLIC_HEADER "queue.h")
install(TARGETS queue PUBLIC_HEADER DESTINATION include/queue)

add_executable(queue_test queue_test.cpp)
target_link_libraries(queue_test queue)
install(TARGETS queue_test DESTINATION bin/c02)