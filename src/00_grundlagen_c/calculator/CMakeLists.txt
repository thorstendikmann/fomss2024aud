
add_executable(00_calculator calc.h main.c getop.c stack.c getch.c)
install(TARGETS 00_calculator DESTINATION bin)
target_link_libraries(00_calculator m) # math

add_executable(00_calculator_allinone allinone.c)
install(TARGETS 00_calculator_allinone DESTINATION bin)
target_link_libraries(00_calculator_allinone m) # math