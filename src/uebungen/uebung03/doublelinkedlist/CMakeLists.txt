add_library(doublelinkedlist doublelinkedlist.c)
set_target_properties(doublelinkedlist PROPERTIES PUBLIC_HEADER "doublelinkedlist.h")
install(TARGETS doublelinkedlist PUBLIC_HEADER DESTINATION include/doublelinkedlist)

add_executable(doublelinkedlist_test doublelinkedlist_test.c)
target_link_libraries(doublelinkedlist_test doublelinkedlist)
install(TARGETS doublelinkedlist DESTINATION bin/u02)