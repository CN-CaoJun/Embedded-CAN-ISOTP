cmake_minimum_required(VERSION 3.10)

###
# Project definition
###
project(isotp_server LANGUAGES C)

set(CMAKE_BUILD_TYPE Debug)

###
# Get all include directories
###
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

SET(ISOTP_SOURCES
    src/isotp.c
    src/isotp_port.c
)


SET(PROJECT_SOURCES
    examples/main.c
)

###
# Compile isotp as Shared Lib
###
# add_library(isotp_lib SHARED
#     src/isotp.c
#     src/isotp_port.c
# )

###
# Add executable and link it with the shared library
###
add_executable(${CMAKE_PROJECT_NAME} ${PROJECT_SOURCES}
${ISOTP_SOURCES}
)

# target_link_libraries(${CMAKE_PROJECT_NAME}
#     isotp_lib
# )