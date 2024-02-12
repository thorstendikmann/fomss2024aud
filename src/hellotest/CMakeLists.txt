enable_testing()
include(GoogleTest)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test)

## Hello World for Google Test
add_executable(
  test_helloworld
  test_helloworld.cpp
)
target_link_libraries(
  test_helloworld
  GTest::gtest_main
)
gtest_discover_tests(test_helloworld)
install(TARGETS test_helloworld DESTINATION test)


## Testing functions in a separate library
add_library(somefunctions somefunctions.c)
set_target_properties(somefunctions PROPERTIES PUBLIC_HEADER "somefunctions.h")
INSTALL(TARGETS somefunctions 
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include
)

add_executable(
  test_somefunctions
  test_somefunctions.cpp
)
target_link_libraries(
  test_somefunctions
  somefunctions
  GTest::gtest_main
)
gtest_discover_tests(test_somefunctions)
install(TARGETS test_somefunctions DESTINATION test)