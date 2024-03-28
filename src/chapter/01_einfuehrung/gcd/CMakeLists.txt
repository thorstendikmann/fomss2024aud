# We create a library out of the GCD file - will be reused in Uebung02
add_library(gcdlib gcd.c gcd.h)
install(TARGETS gcdlib DESTINATION lib/c01)

add_executable(gcd gcd_main.c)
install(TARGETS gcd DESTINATION bin/c01)
target_link_libraries(gcd gcdlib)
