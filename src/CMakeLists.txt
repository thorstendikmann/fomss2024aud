# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14) # 17
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_C_FLAGS "-g -Wall -Wextra -pedantic -Werror -Wstrict-prototypes")
set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -pedantic -Werror")

MESSAGE(STATUS "CMAKE_BUILD_TYPE       = ${CMAKE_BUILD_TYPE}")
MESSAGE(STATUS "CMAKE_INSTALL_PREFIX   = ${CMAKE_INSTALL_PREFIX}")
MESSAGE(STATUS "BUILD_SHARED_LIBS      = ${BUILD_SHARED_LIBS}")
MESSAGE(STATUS "CMAKE_C_FLAGS          = ${CMAKE_C_FLAGS}")
MESSAGE(STATUS "CMAKE_CXX_FLAGS        = ${CMAKE_CXX_FLAGS}")
MESSAGE(STATUS "CMAKE_EXE_LINKER_FLAGS = ${CMAKE_EXE_LINKER_FLAGS}")
MESSAGE(STATUS "CMAKE_SYSTEM_NAME      = ${CMAKE_SYSTEM_NAME}")

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
endif()

## Macro for adding all subdirectories
MACRO(td_add_all_subdirectories)
    FILE(GLOB children LIST_DIRECTORIES true "*")
        SET(dirlist "")
        FOREACH(child ${children})
            IF(IS_DIRECTORY ${curdir}/${child})
                add_subdirectory(${child})
        ENDIF()
    ENDFOREACH()
ENDMACRO()

# Install run.sh
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/run.sh DESTINATION bin 
        PERMISSIONS OWNER_READ
        PERMISSIONS OWNER_WRITE
        PERMISSIONS OWNER_EXECUTE
        PERMISSIONS GROUP_READ
        PERMISSIONS GROUP_EXECUTE
        PERMISSIONS WORLD_READ
        PERMISSIONS WORLD_EXECUTE
)

## Boost
if(WITH_BOOST)
    message("-- Searching for Boost libraries")
    set(Boost_USE_STATIC_LIBS OFF)
    set(Boost_USE_MULTITHREADED OFF)
    set(Boost_USE_STATIC_RUNTIME OFF)
    # Replace "ALL" - Add only needed components
    find_package(Boost 1.74 REQUIRED COMPONENTS ALL)
endif(WITH_BOOST)

## Google Test
if(WITH_GTEST)
    message("-- Searching for GTest libraries")
    find_package(GTest REQUIRED)
endif(WITH_GTEST)

add_subdirectory(helloworlds)
add_subdirectory(chapter)
add_subdirectory(uebungen)
add_subdirectory(user)
