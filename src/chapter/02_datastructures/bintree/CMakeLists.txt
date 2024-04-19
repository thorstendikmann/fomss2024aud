add_library(bintree bintree.cpp)
set_target_properties(bintree PROPERTIES PUBLIC_HEADER "bintree.h")
install(TARGETS bintree PUBLIC_HEADER DESTINATION include/bintree)

add_executable(bintree_test bintree_test.cpp)
target_link_libraries(bintree_test bintree)
install(TARGETS bintree_test DESTINATION bin/c02)