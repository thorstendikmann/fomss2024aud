add_library(searcharray searcharray.cpp searcharray.h)
set_target_properties(searcharray PROPERTIES PUBLIC_HEADER "searcharray.h")
install(TARGETS searcharray PUBLIC_HEADER DESTINATION include/searcharray)

add_executable(searcharray_test searcharray_test.cpp)
target_link_libraries(searcharray_test searcharray)
install(TARGETS searcharray_test DESTINATION bin/c04)