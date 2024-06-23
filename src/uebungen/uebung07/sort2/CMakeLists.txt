add_executable(countingsort countingsort.cpp)
target_link_libraries(countingsort countingsortarray)
install(TARGETS countingsort DESTINATION bin/u07)

add_executable(radixsort radixsort.cpp)
target_link_libraries(radixsort radixsortarray)
install(TARGETS radixsort DESTINATION bin/u07)