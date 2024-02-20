cmake_minimum_required(VERSION 3.18)

project(AuD  VERSION 1.0.0  DESCRIPTION "Algorithms & Datastructures examples")

#enable_language(C CXX ASM ASM_NASM)
enable_language(C CXX ASM)

add_subdirectory(src)

##
## Doxygen
##
option(BUILD_DOC "Build documentation" ON)

find_package(Doxygen)
if (DOXYGEN_FOUND)
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    CONFIGURE_FILE(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("-- Doxygen build configured")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating Doxygen documentation"
        VERBATIM )
    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/doc/ DESTINATION share/doc)
else (DOXYGEN_FOUND)
    message(WARNING "-- Install Doxygen to generate documentation.")
endif (DOXYGEN_FOUND)