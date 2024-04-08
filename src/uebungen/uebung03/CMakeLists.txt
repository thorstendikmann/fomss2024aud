set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/u03)

add_executable(gcd_benchmark gcd_benchmark.c)
install(TARGETS gcd_benchmark DESTINATION bin/u03)
# Link to target from chapter/01_einfuehrung
target_link_libraries(gcd_benchmark gcdlib)

add_executable(guessinggame guessinggame.c)
install(TARGETS guessinggame DESTINATION bin/u03)

td_add_all_subdirectories()