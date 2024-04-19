add_library(dynarray dynarray.cpp)
set_target_properties(dynarray PROPERTIES PUBLIC_HEADER "dynarray.h")
install(TARGETS dynarray PUBLIC_HEADER DESTINATION include/dynarray)

add_executable(dynarray_test dynarray_test.cpp)
target_link_libraries(dynarray_test dynarray)
install(TARGETS dynarray_test DESTINATION bin/c02)