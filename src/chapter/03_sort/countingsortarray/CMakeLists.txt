add_library(countingsortarray countingsortarray.cpp countingsortarray.h)
set_target_properties(countingsortarray PROPERTIES PUBLIC_HEADER "countingsortarray.h")
install(TARGETS countingsortarray PUBLIC_HEADER DESTINATION include/countingsortarray)

add_executable(countingsortarray_test countingsortarray_test.cpp)
target_link_libraries(countingsortarray_test countingsortarray)
install(TARGETS countingsortarray_test DESTINATION bin/c03)