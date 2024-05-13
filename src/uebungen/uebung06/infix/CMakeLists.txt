set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/u06)

add_executable(infix_parser infix_parser.cpp)
target_link_libraries(infix_parser stack)
install(TARGETS infix_parser DESTINATION bin/u06)