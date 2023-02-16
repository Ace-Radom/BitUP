add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cvector)
# build cvector subproject

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/filesystem)
# build filesystem subproject

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/renalog)
# build renalog subproject

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/bitupignore)
# build bitupignore subproject

add_library(hash SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/hash.cpp
)
target_link_libraries(hash
    OpenSSL::Crypto
    OpenSSL::SSL
)