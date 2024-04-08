add_library(array array.c)
set_target_properties(array PROPERTIES PUBLIC_HEADER "array.h")
install(TARGETS array PUBLIC_HEADER DESTINATION include/array)

add_executable(array_test array_test.c)
target_link_libraries(array_test array)
install(TARGETS array_test DESTINATION bin/c02)