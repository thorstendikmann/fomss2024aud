
add_executable(00_simplefunctions simplefunctions.c)
install(TARGETS 00_simplefunctions DESTINATION bin)

add_executable(00_arrays arrays.c)
install(TARGETS 00_arrays DESTINATION bin)

add_executable(00_structs structs.c)
install(TARGETS 00_structs DESTINATION bin)

add_executable(00_input input.c)
install(TARGETS 00_input DESTINATION bin)

add_executable(00_pointer pointer.c)
install(TARGETS 00_pointer DESTINATION bin)

add_executable(00_fahrenheit fahrenheit.c)
install(TARGETS 00_fahrenheit DESTINATION bin)

add_subdirectory("calculator")