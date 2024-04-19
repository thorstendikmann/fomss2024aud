add_library(circularbuffer circularbuffer.c)
set_target_properties(circularbuffer PROPERTIES PUBLIC_HEADER "circularbuffer.h")
install(TARGETS circularbuffer PUBLIC_HEADER DESTINATION include/circularbuffer)

add_executable(circularbuffer_test circularbuffer_test.c)
target_link_libraries(circularbuffer_test circularbuffer)
install(TARGETS circularbuffer DESTINATION bin/u02)