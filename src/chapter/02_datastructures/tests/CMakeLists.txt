
if(WITH_GTEST)
    
    enable_testing()
    include(GoogleTest)

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test)

    ## DynArray (C++ Array)
    add_executable(test_dynarray test_dynarray.cpp)
    target_link_libraries(test_dynarray GTest::gtest_main)
    gtest_discover_tests(test_dynarray)
    install(TARGETS test_dynarray DESTINATION test)

endif(WITH_GTEST)