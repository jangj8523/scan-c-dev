cmake_minimum_required (VERSION 2.6)
project (Tutorial)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")


# The version number.
set (Lidar_version 1)
set (SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set (BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set (INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include usr/include)
set (LIB_DIR ${PROJECT_SOURCE_DIR}/lib)
set (TEST_DIR ${PROJECT_SOURCE_DIR}/test)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/build)

# include Standard C library and our custom header files
include_directories ( ${INCLUDE_DIR} )

# include MOSQUITTO C library
include_directories (usr/local/include)

message(STATUS, ${PROJECT_SOURCE_DIR})

add_executable(main_exec src/main.c)

# add_subdirectory(${PROJECT_SOURCE_DIR}/src)
