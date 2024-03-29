# We create a library out of the GCD file - will be reused in Uebung02
add_library(gcdlib gcd.c)
set_target_properties(gcdlib PROPERTIES PUBLIC_HEADER "gcd.h")
install(TARGETS gcdlib PUBLIC_HEADER DESTINATION include/gcd)

add_executable(gcd gcd_main.c)
install(TARGETS gcd DESTINATION bin/c01)
target_link_libraries(gcd gcdlib)
