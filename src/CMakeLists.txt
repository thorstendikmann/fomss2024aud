# GoogleTest requires at least C++14
## https://cmake.org/cmake/help/latest/prop_tgt/CXX_STANDARD.html
set(CMAKE_CXX_STANDARD 14) #98 #11 #14 #17 #20 #23 #26
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
## https://cmake.org/cmake/help/latest/prop_tgt/C_STANDARD.html
set(CMAKE_C_STANDARD 99) #90 #99 #11 #17 #23
set(CMAKE_C_STANDARD_REQUIRED TRUE)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # using Clang
    ## https://clang.llvm.org/docs/DiagnosticsReference.html
    ## -Wshadow-all - for warnings on shadowing variables
    set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -Werror")

    if (CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
        # using clang with clang-cl front end
    elseif (CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "GNU")
        # using clang with regular front end
    endif()
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # using GCC
    ## Yes, "-pedantic" without 'W', see https://gcc.gnu.org/onlinedocs/gcc-4.7.4/gcc/Warning-Options.html#index-pedantic-252
    set(CMAKE_CXX_FLAGS "-g3 -ggdb -O0 -Wall -Wextra -pedantic -Werror -Wstrict-aliasing")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
    # using Intel C++
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # using Visual Studio C++
endif()

if (CMAKE_C_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_C_FLAGS "-g -Wall -Wextra -Werror")
elseif (CMAKE_C_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_C_FLAGS "-g3 -ggdb -O0 -Wall -Wextra -pedantic -Werror -Wstrict-prototypes -Wstrict-aliasing")
elseif (CMAKE_C_COMPILER_ID STREQUAL "Intel")
elseif (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
endif()

# Manually select lld as linker
if(USE_LLD)
    # Replace in future: CMake 3.29 -> CMAKE_LINKER_TYPE
    add_link_options("-fuse-ld=lld")
endif(USE_LLD)


MESSAGE(STATUS "CMAKE_BUILD_TYPE       = ${CMAKE_BUILD_TYPE}")
MESSAGE(STATUS "CMAKE_C_COMPILER_ID    = ${CMAKE_C_COMPILER_ID} ${CMAKE_C_COMPILER_VERSION}")
MESSAGE(STATUS "CMAKE_CXX_COMPILER_ID  = ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
MESSAGE(STATUS "CMAKE_INSTALL_PREFIX   = ${CMAKE_INSTALL_PREFIX}")
MESSAGE(STATUS "BUILD_SHARED_LIBS      = ${BUILD_SHARED_LIBS}")
MESSAGE(STATUS "CMAKE_C_FLAGS          = ${CMAKE_C_FLAGS}")
MESSAGE(STATUS "CMAKE_CXX_FLAGS        = ${CMAKE_CXX_FLAGS}")
MESSAGE(STATUS "CMAKE_EXE_LINKER_FLAGS = ${CMAKE_EXE_LINKER_FLAGS}")
MESSAGE(STATUS "CMAKE_SYSTEM_NAME      = ${CMAKE_SYSTEM_NAME}")
MESSAGE(STATUS "CMAKE_C_STANDARD       = ${CMAKE_C_STANDARD}")
MESSAGE(STATUS "CMAKE_CXX_STANDARD     = ${CMAKE_CXX_STANDARD}")

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    add_definitions(-DLINUX)
    add_definitions(-DUNIX)
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Unix")
    add_definitions(-DUNIX)
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    add_definitions(-DMACOS)
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  add_definitions(-DWINDOWS)
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

## Macro for adding all subdirectories
MACRO(td_add_all_subdirectories)
    FILE(GLOB children LIST_DIRECTORIES true "*")
    SET(dirlist "")
    FOREACH(child ${children})
        IF(IS_DIRECTORY ${child})
            MESSAGE(VERBOSE "Adding folder ${curdir}/${child} to build.")
            add_subdirectory(${child})
        ENDIF()
    ENDFOREACH()
ENDMACRO()

## Macro for adding all subdirectories to include_directories
## Specify relative dir as optional argument!
MACRO(td_include_subdirectories)
    SET(OPTIONAL_PATH ${ARGN})
    MESSAGE(DEBUG "OPTIONAL_PATH: ${OPTIONAL_PATH}")
    IF(NOT OPTIONAL_PATH STREQUAL "")
        FILE(GLOB children LIST_DIRECTORIES true "${OPTIONAL_PATH}/*")
    ELSE()
        FILE(GLOB children LIST_DIRECTORIES true "*")
    ENDIF()

    SET(dirlist "")
    FOREACH(child ${children})
        IF(IS_DIRECTORY ${child})
            MESSAGE(VERBOSE "Include_directories: ${child}")
            include_directories(${child})
        ENDIF()
    ENDFOREACH()
ENDMACRO()

## Boost
if(WITH_BOOST)
    message("-- Searching for Boost libraries")
    set(Boost_USE_STATIC_LIBS OFF)
    set(Boost_USE_MULTITHREADED OFF)
    set(Boost_USE_STATIC_RUNTIME OFF)
    find_package(Boost 1.74 REQUIRED COMPONENTS log)
    
    message("-- Found Boost libraries: ${Boost_LIBRARIES}")
    
    link_directories( $ENV{LD_LIBRARY_PATH}
        ${Boost_LIBRARY_DIRS}
    )
    include_directories(
        $ENV{LD_INCLUDE_PATH}
        ${Boost_INCLUDE_DIR}
    )
endif(WITH_BOOST)

## Google Test
if(WITH_GTEST)
    message("-- Searching for GTest libraries")
    find_package(GTest REQUIRED)
endif(WITH_GTEST)

td_include_subdirectories("chapter")
add_subdirectory(helloworlds)
add_subdirectory(chapter)
add_subdirectory(uebungen)
add_subdirectory(snippets)
td_include_subdirectories(user)
add_subdirectory(user)
