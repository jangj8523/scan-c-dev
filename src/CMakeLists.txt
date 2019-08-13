cmake_minimum_required (VERSION 2.6)
project (Tutorial)

# The version number.
set (Lidar_version 1)

include_directories (../include)

add_library (lidar SHARED lidar.c)
set_target_properties(lidar PROPERTIES LIBRARY_OUTPUT_DIRECTORY ../bin)
