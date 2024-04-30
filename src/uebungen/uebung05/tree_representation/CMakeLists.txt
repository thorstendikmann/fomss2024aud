set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/u05)

add_executable(tree_representation tree_representation.cpp)
target_link_libraries(tree_representation treearray)
install(TARGETS tree_representation DESTINATION bin/u05)