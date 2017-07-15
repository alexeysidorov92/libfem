cmake_minimum_required(VERSION 3.2)
set(CMAKE_CONFIGURATION_TYPES Debug Release CACHE TYPE INTERNAL FORCE)
project(libfem.project)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules")

add_subdirectory("${CMAKE_SOURCE_DIR}/libfem")
