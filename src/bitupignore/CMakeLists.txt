cmake_minimum_required(VERSION 3.10)
project(bitupignore VERSION 1.0)
# subproject under main: BitUP

# this subproject provides a parser for .bitupignore

set(BITUPIGNORE_PARSER_MAIN ${CMAKE_CURRENT_SOURCE_DIR}/bitupignore_parser.c)

add_executable(bip
    ${BITUPIGNORE_PARSER_MAIN}
)

target_link_libraries(bip
    filesystem
)