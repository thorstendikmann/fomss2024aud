add_executable(invsqrt invsqrt.c)
install(TARGETS invsqrt DESTINATION bin/c01)
target_link_libraries(invsqrt m) # math
