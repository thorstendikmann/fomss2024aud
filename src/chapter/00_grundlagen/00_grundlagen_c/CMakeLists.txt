
add_executable(simplefunctions simplefunctions.c)
install(TARGETS simplefunctions DESTINATION bin/c00)
if (NOT WIN32)
    target_link_libraries(simplefunctions m) # math
endif()

add_executable(arrays arrays.c)
install(TARGETS arrays DESTINATION bin/c00)

add_executable(structs structs.c)
install(TARGETS structs DESTINATION bin/c00)

add_executable(input input.c)
install(TARGETS input DESTINATION bin/c00)

add_executable(pointer pointer.c)
install(TARGETS pointer DESTINATION bin/c00)

add_executable(fahrenheit fahrenheit.c)
install(TARGETS fahrenheit DESTINATION bin/c00)

add_subdirectory("calculator")