add_library(avltree avltree.cpp)
target_link_libraries(avltree binsearchtree bintree)
set_target_properties(avltree PROPERTIES PUBLIC_HEADER "avltree.h")
install(TARGETS avltree PUBLIC_HEADER DESTINATION include/avltree)

add_executable(avltree_test avltree_test.cpp)
target_link_libraries(avltree_test avltree binsearchtree bintree)
install(TARGETS avltree_test DESTINATION bin/c02)

add_executable(avltree_rotation avltree_rotation.cpp)
target_link_libraries(avltree_rotation avltree binsearchtree bintree)
install(TARGETS avltree_rotation DESTINATION bin/c02)

add_executable(avltree_insert avltree_insert.cpp)
target_link_libraries(avltree_insert avltree binsearchtree bintree)
install(TARGETS avltree_insert DESTINATION bin/c02)