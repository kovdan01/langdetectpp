cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(tests
        VERSION 0.0.0
        LANGUAGES CXX
)

# langdetectpp
find_package(langdetectpp REQUIRED)

# folly facebook
find_package(Folly REQUIRED)

add_executable(${PROJECT_NAME}
    src/tests.cpp
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

target_link_libraries(${PROJECT_NAME} PRIVATE
    langdetectpp::langdetectpp
    Folly::folly
)

ntc_target(${PROJECT_NAME})
