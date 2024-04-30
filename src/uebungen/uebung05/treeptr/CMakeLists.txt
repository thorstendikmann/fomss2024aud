add_library(treeptr treeptr.c)
install(TARGETS treeptr)

add_executable(treeptr_test treeptr_test.c)
if (NOT WIN32)
    target_link_libraries(treeptr_test treeptr m)
else()
    target_link_libraries(treeptr_test treeptr)
endif()
