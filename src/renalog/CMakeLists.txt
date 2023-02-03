cmake_minimum_required(VERSION 3.10)
project(renalog VERSION 1.0)
# subproject under main: BitUP

# this project is cloned from https://github.com/Ace-Radom/renalog, matched version 1.0

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)

# don't like the original project, this one will compile all functions into one dll
# because renalog_reader is absolutely used by the main project

include_directories(${CMAKE_SOURCE_DIR}/include)

aux_source_directory(. RENALOG_SRC)
add_library(renalog SHARED
    ${RENALOG_SRC}
)