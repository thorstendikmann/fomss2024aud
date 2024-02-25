set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/hello)

## C/C++ Hello World
add_subdirectory(helloworld)

## Boost
if(WITH_BOOST)
    if (BOOST_FOUND)
        message(STATUS "Boost version: ${Boost_VERSION}")
        message(STATUS "Boost libraries: ${Boost_LIBRARIES}")
        INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
        add_subdirectory(helloboost)
    else(BOOST_FOUND)
        message(FATAL_ERROR "-- Boost libraries not installed.")
    endif (BOOST_FOUND)
endif(WITH_BOOST)

## Google Test
if(WITH_GTEST)
    if (GTest_FOUND)
        INCLUDE_DIRECTORIES( ${GTEST_INCLUDE_DIRS} )
        add_subdirectory(hellotest)
    else(GTest_FOUND)
        message(FATAL_ERROR "-- Googletest libraries not installed.")
    endif (GTest_FOUND)
endif(WITH_GTEST)

## Assembler
if(WITH_ASM)
    add_subdirectory(helloasm)
endif(WITH_ASM)

## Rust
if(WITH_RUST)
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
endif(WITH_RUST)
