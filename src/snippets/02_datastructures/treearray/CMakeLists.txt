add_executable(treearray_test_snp treearray.c treearray_test.c)
if (NOT WIN32)
    target_link_libraries(treearray_test_snp m)
endif()
