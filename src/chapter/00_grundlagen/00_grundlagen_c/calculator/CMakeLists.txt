
add_executable(calculator_input calc.h main.c getop.c stack.c getch.c)
install(TARGETS calculator_input DESTINATION bin/c00)
if (NOT WIN32)
    target_link_libraries(calculator_input m) # math
endif()

add_executable(calculator_allinone_input allinone.c)
install(TARGETS calculator_allinone_input DESTINATION bin/c00)
if (NOT WIN32)
    target_link_libraries(calculator_allinone_input m) # math
endif()