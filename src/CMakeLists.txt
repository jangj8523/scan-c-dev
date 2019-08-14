cmake_minimum_required (VERSION 2.6)
project (Tutorial)

# The version number.
set (Lidar_version 1)

include_directories (../include)
SET(LIBS_SYSTEM c pthread usr/local/lib)

add_library (lidar SHARED lidar.c)
# target_link_libraries(lidar ${PROJECT_SOURCE_DIR}/build/src/libpaho-mqtt3a.dylib)
# target_link_libraries(lidar /usr/local/lib/libpaho-mqtt3c.1.3.1.dylib)
target_link_libraries(lidar /usr/local/lib/libpaho-mqtt3c.so.1.2.1)
set_target_properties(lidar PROPERTIES LIBRARY_OUTPUT_DIRECTORY ../bin)
