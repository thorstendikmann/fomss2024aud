add_executable(hello_world_asm helloworld.s)
TARGET_LINK_LIBRARIES(hello_world_asm -nostdlib)
install(TARGETS hello_world_asm DESTINATION bin/hello)
