add_library(linkedlist linkedlist.c)
set_target_properties(linkedlist PROPERTIES PUBLIC_HEADER "linkedlist.h")
install(TARGETS linkedlist PUBLIC_HEADER DESTINATION include/linkedlist)

add_executable(linkedlist_test linkedlist_test.c)
target_link_libraries(linkedlist_test linkedlist)
install(TARGETS linkedlist_test DESTINATION bin/c02)