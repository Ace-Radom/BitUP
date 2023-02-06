cmake_minimum_required(VERSION 3.10)
project(c_filesystem VERSION 1.0)
# subproject under main: BitUP

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
add_definitions(-DEXPORTING_APIS)

include_directories(${CMAKE_SOURCE_DIR}/include)

aux_source_directory(. C_FILESYSTEM_SRC)
add_library(filesystem SHARED 
    ${C_FILESYSTEM_SRC}
)
target_link_libraries(filesystem
    cvector
)