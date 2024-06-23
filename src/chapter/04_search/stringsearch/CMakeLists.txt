add_library(fomstring fomstring.cpp fomstring.h)
set_target_properties(fomstring PROPERTIES PUBLIC_HEADER "fomstring.h")
install(TARGETS fomstring PUBLIC_HEADER DESTINATION include/stringsearch)

add_executable(stringsearch_test stringsearch_test.cpp)
target_link_libraries(stringsearch_test fomstring)
install(TARGETS stringsearch_test DESTINATION bin/c04)