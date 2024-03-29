cmake_minimum_required(VERSION 3.18)

project(AuD  VERSION 0.1.0  DESCRIPTION "Algorithms & Datastructures examples")
enable_language(C CXX)

##
## Project Options
##
option(WITH_DOC "Build documentation" OFF)
option(WITH_RUST "Build rust hello world examples?" OFF)
option(WITH_ASM "Build assembler hello world examples?" OFF)
option(WITH_GTEST "Build Google Test examples and require GTest libs?" OFF)
option(WITH_BOOST "Build Boost examples and require Boost libs?" OFF)
option(WITH_VIS "Build GUI examples (requires Qt and other libs)?" OFF) # WITH_VISUALIZATION ... just shorter
option(USE_LLD "Use LLD instead of ld" OFF) # in future: CMake 3.29 -> CMAKE_LINKER_TYPE

if(WITH_ASM)
    message("-- Adding Assembler language")
    #enable_language(ASM ASM_NASM)
    enable_language(ASM)
endif(WITH_ASM)

## Packaging
set(CPACK_GENERATOR "DEB;ZIP;TGZ")
set(CPACK_SOURCE_GENERATOR "DEB;ZIP;TGZ")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Thorsten Dikmann")
set(CPACK_DEBIAN_PACKAGE_HOMEPAGE "https://github.com/thorstendikmann/fomss2024aud")
set(CPACK_DEB_COMPONENT_INSTALL ON)
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
set(CPACK_DEBIAN_PACKAGE_GENERATE_SHLIBS ON)
include(CPack)

##
## Do all the work ...
##
add_subdirectory(src)

##
## Doxygen
##
if(WITH_DOC)
    message("-- Searching for Doxygen")
    find_package(Doxygen REQUIRED)
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
endif(WITH_DOC)