add_executable(searchstring searchstring.cpp)
target_link_libraries(searchstring fomstring)
install(TARGETS searchstring DESTINATION bin/u07)