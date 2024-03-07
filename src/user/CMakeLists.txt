# All binaries will end up in bin/user/ folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/user)

# Just include all subdirectories here
# Make sure there is a CMakeLists.txt in every subdirectory
td_add_all_subdirectories()