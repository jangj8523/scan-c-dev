cmake_minimum_required (VERSION 2.6)
project (Tutorial)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")
set(CMAKE_BUILD_TYPE Debug)


# The version number.
set (Lidar_version 1)

if (APPLE)
  set (CMAKE_OS_NAME "OSX" CACHE STRING "Operating system name" FORCE)
else (APPLE)
  ## Check for Debian GNU/Linux ________________
  find_file (DEBIAN_FOUND debian_version debconf.conf
    PATHS /etc
)
if (DEBIAN_FOUND)
  set (CMAKE_OS_NAME "Debian" CACHE STRING "Operating system name" FORCE)
  if (UBUNTU_FOUND)
	  set (CMAKE_OS_NAME "Ubuntu" CACHE STRING "Operating system name" FORCE)
	  set (DEBIAN_FOUND FALSE)
	endif (UBUNTU_FOUND)
  endif (DEBIAN_FOUND)
endif (APPLE)

if (UBUNTU_FOUND)
  message("UBUNTU FOUND")
endif (UBUNTU_FOUND)

# Set Varaible paths
set (SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set (BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set (LIB_DIR ${PROJECT_SOURCE_DIR}/lib)
set (INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include usr/include usr/local/lib /usr/local/include ${LIB_DIR}/paho.mqtt.c/src)
set (TEST_DIR ${PROJECT_SOURCE_DIR}/test)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

# include Standard C library and our custom header files
include_directories ( ${INCLUDE_DIR} )

# include MOSQUITTO C library
include_directories (usr/local/include)

message(STATUS, ${PROJECT_SOURCE_DIR})

add_executable(main_exec src/main.c)
target_link_libraries(main_exec ${BIN_DIR}/liblidar.so)
# target_link_libraries(main_exec ${BIN_DIR}/liblidar.dylib)

# add_subdirectory(${PROJECT_SOURCE_DIR}/src)
