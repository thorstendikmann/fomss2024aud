
add_executable(helloboost helloboost.cpp)
target_link_libraries(helloboost ${Boost_LIBRARIES})
install(TARGETS helloboost DESTINATION bin)
