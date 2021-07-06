cmake_minimum_required(VERSION 3.0)
project(gtkopen C CXX)

# Use the package PkgConfig to detect GTK+ headers/library files
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtkmm-3.0)

add_executable(gtkopen gtkopen.cpp)

target_link_directories(gtkopen PRIVATE ${GTK_LIBRARY_DIRS})
target_include_directories(gtkopen PRIVATE ${GTK_INCLUDE_DIRS})
target_link_libraries(gtkopen PRIVATE ${GTK_LIBRARIES})