add_executable(invsqrt_benchmark invsqrt.c)
install(TARGETS invsqrt_benchmark DESTINATION bin/c01)

if (NOT WIN32)
    target_link_libraries(invsqrt_benchmark m) # math
endif()