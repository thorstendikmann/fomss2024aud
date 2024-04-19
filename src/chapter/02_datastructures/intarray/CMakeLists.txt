add_library(intarray intarray.c)
set_target_properties(intarray PROPERTIES PUBLIC_HEADER "intarray.h")
install(TARGETS intarray PUBLIC_HEADER DESTINATION include/intarray)

add_executable(intarray_test intarray_test.c)
target_link_libraries(intarray_test intarray)
install(TARGETS intarray_test DESTINATION bin/c02)