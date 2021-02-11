cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(langdetectpp
        VERSION 0.0.0
        LANGUAGES CXX
)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/ntc")
include(ntc-dev-build)

option(LANGDETECTPP_BUILD_TESTS "Build tests" OFF)

add_subdirectory(langdetectpp)

if(LANGDETECTPP_BUILD_TESTS)
    add_subdirectory(tests)
endif()
