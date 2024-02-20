message(STATUS "CMAKE_SYSTEM_PROCESSOR = ${CMAKE_SYSTEM_PROCESSOR}")

IF(CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64")
    message(STATUS "Generating x86_64 assembly.")
    add_subdirectory(x86_64)
ENDIF()
IF(CMAKE_SYSTEM_PROCESSOR STREQUAL "ARM")
    add_subdirectory(arm)
ENDIF()