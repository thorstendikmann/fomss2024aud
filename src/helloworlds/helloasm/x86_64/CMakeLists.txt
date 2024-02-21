set(CMAKE_EXE_LINKER_FLAGS "-no-pie")

add_executable(hello_world_asm_x86_64_atat helloworld_atat.s)
TARGET_LINK_LIBRARIES(hello_world_asm_x86_64_atat -nostdlib)
install(TARGETS hello_world_asm_x86_64_atat DESTINATION bin/hello)

add_executable(hello_world_asm_x86_64_intel helloworld_intel.s)
TARGET_LINK_LIBRARIES(hello_world_asm_x86_64_intel -nostdlib)
install(TARGETS hello_world_asm_x86_64_intel DESTINATION bin/hello)
