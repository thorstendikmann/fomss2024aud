add_executable(hello_world_cpp helloworld.cpp)
install(TARGETS hello_world_cpp DESTINATION bin/hello)

add_executable(hello_world_c helloworld.c)
install(TARGETS hello_world_c DESTINATION bin/hello)
