set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/u01)

add_executable(rechteck rechteck.c)
install(TARGETS rechteck DESTINATION bin/u01)

add_executable(datum datum.c)
install(TARGETS datum DESTINATION bin/u01)

add_executable(eingabe eingabe.c)
install(TARGETS eingabe DESTINATION bin/u01)
target_link_libraries(eingabe m) # math

add_executable(algorithmen algorithmen.c)
install(TARGETS algorithmen DESTINATION bin/u01)
target_link_libraries(algorithmen m) # math
