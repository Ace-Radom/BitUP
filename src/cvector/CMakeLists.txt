cmake_minimum_required(VERSION 3.10)
project(cvector VERSION 1.0)
# subproject under main: BitUP

add_definitions(-DEXPORTING_APIS)

include_directories(${CMAKE_SOURCE_DIR}/include)

aux_source_directory(. CVECTOR_SRC)
add_library(cvector SHARED
    ${CVECTOR_SRC}
)