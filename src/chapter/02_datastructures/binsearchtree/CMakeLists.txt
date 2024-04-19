add_library(binsearchtree binsearchtree.cpp)
target_link_libraries(binsearchtree bintree)
set_target_properties(binsearchtree PROPERTIES PUBLIC_HEADER "binsearchtree.h")
install(TARGETS binsearchtree PUBLIC_HEADER DESTINATION include/binsearchtree)

add_executable(binsearchtree_test binsearchtree_test.cpp)
target_link_libraries(binsearchtree_test binsearchtree bintree)
install(TARGETS binsearchtree_test DESTINATION bin/c02)

# Excercise from lecture
add_executable(binsearchtree_insert binsearchtree_insert.cpp)
target_link_libraries(binsearchtree_insert binsearchtree bintree)
install(TARGETS binsearchtree_insert DESTINATION bin/c02)