
add_executable(calculator calc.h main.c getop.c stack.c getch.c)
install(TARGETS calculator DESTINATION bin/c00)
target_link_libraries(calculator m) # math

add_executable(calculator_allinone allinone.c)
install(TARGETS calculator_allinone DESTINATION bin/c00)
target_link_libraries(calculator_allinone m) # math