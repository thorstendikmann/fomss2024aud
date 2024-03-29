add_executable(invsqrt invsqrt.c)
install(TARGETS invsqrt DESTINATION bin/c01)

if (NOT WIN32)
    target_link_libraries(invsqrt m) # math
endif()