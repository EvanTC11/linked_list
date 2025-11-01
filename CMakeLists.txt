cmake_minimum_required(VERSION 3.10)

project(LinkedList VERSION 1.0 LANGUAGES C)

# Set C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Create static library
add_library(linked_list STATIC
    src/linked_list.c
    src/node.c
)

# Specify include directories for the library
target_include_directories(linked_list PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Create executable
add_executable(main src/main.c)

# Link the library to the executable
target_link_libraries(main PRIVATE linked_list)

set_target_properties(
    linked_list main PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
