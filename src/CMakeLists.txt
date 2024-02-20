# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14) # 17
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -pedantic")

MESSAGE(STATUS "CMAKE_BUILD_TYPE       = ${CMAKE_BUILD_TYPE}")
MESSAGE(STATUS "CMAKE_INSTALL_PREFIX   = ${CMAKE_INSTALL_PREFIX}")
MESSAGE(STATUS "BUILD_SHARED_LIBS      = ${BUILD_SHARED_LIBS}")
MESSAGE(STATUS "CMAKE_C_FLAGS          = ${CMAKE_C_FLAGS}")
MESSAGE(STATUS "CMAKE_CXX_FLAGS        = ${CMAKE_CXX_FLAGS}")
MESSAGE(STATUS "CMAKE_EXE_LINKER_FLAGS = ${CMAKE_EXE_LINKER_FLAGS}")

add_subdirectory(helloworld)
add_subdirectory(00_grundlagen_c)
add_subdirectory(00_grundlagen_cpp)

add_subdirectory(user)

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

##
## Boost
##
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED OFF)
set(Boost_USE_STATIC_RUNTIME OFF)
# Replace "ALL" - Add only needed components
find_package(Boost 1.74 REQUIRED COMPONENTS ALL)

if (BOOST_FOUND)
    message(STATUS "Boost version: ${Boost_VERSION}")
    message(STATUS "Boost libraries: ${Boost_LIBRARIES}")
    INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
    add_subdirectory(helloboost)
else(BOOST_FOUND)
    message(WARNING "-- Boost libraries not installed.")
endif (BOOST_FOUND)

##
## Google Test
##
find_package(GTest)
if (GTest_FOUND)
    INCLUDE_DIRECTORIES( ${GTEST_INCLUDE_DIRS} )
    add_subdirectory(hellotest)
else(GTest_FOUND)
    message(WARNING "-- Googletest libraries not installed.")
endif (GTest_FOUND)

##
## Assembler examples
##
IF(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    add_subdirectory(helloasm)
ENDIF()

##
## Rust examples
##
find_file (RUST_CARGO cargo)
find_file (RUST_RUSTC rustc)
if(RUST_CARGO AND RUST_RUSTC)
    message("-- rustc installation found: ${RUST_RUSTC}")
    message("-- cargo installation found: ${RUST_CARGO}")
    
    # target hellorust is always built
    add_custom_target(hellorust
        ALL
        COMMAND cd ${CMAKE_CURRENT_SOURCE_DIR}/hellorust && export CARGO_TARGET_DIR=${CMAKE_BINARY_DIR}/rust && cargo build
        VERBATIM
    )
endif()
