add_executable(visualizations visualizations.cpp)
target_link_libraries(visualizations array linkedlist stack queue)
install(TARGETS visualizations DESTINATION bin/u04)