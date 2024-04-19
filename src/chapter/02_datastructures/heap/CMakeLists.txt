add_library(heap heap.cpp)
set_target_properties(heap PROPERTIES PUBLIC_HEADER "heap.h")
install(TARGETS heap PUBLIC_HEADER DESTINATION include/heap)

add_executable(heap_test heap_test.cpp)
target_link_libraries(heap_test dynarray)
install(TARGETS heap_test DESTINATION bin/c02)