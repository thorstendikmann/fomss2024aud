set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/u06)

add_executable(tree_traverse tree_traverse.cpp)
target_link_libraries(tree_traverse treearray)
install(TARGETS tree_traverse DESTINATION bin/u06)