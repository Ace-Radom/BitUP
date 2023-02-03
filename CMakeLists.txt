cmake_minimum_required(VERSION 3.10)
project(BitUP VERSION 1.0)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)

set(BUILD_TEST ON)

# ============================================
#                search OpenSSL
# ============================================

find_package(OpenSSL REQUIRED)
if(NOT OPENSSL_FOUND)
    message(FATAL "Cannot found OpenSSL, please check environment")
endif()

include_directories(${OPENSSL_INCLUDE_DIR})

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/debug)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/debug)

# ============================================
#                  build proj
# ============================================

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(${CMAKE_SOURCE_DIR}/src)

# ============================================
#                  build test
# ============================================

if(${BUILD_TEST})

    add_executable(test test.cpp)
    target_link_libraries(test
        filesystem
        hash
    )

endif()