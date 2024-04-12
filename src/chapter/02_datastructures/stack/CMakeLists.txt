add_library(stack stack.cpp)
target_link_libraries(stack linkedlist)
set_target_properties(stack PROPERTIES PUBLIC_HEADER "stack.h")
install(TARGETS stack PUBLIC_HEADER DESTINATION include/stack)

add_executable(stack_test stack_test.cpp)
target_link_libraries(stack_test stack)
install(TARGETS stack_test DESTINATION bin/c02)