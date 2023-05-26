cmake_minimum_required(VERSION 3.0.0)
project(Eat-The-Mushroom LANGUAGES CXX VERSION 3.0)

include(CTest)
enable_testing()

add_subdirectory(3rdparty)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE 
    src/main.cpp
)
target_link_libraries(${PROJECT_NAME} PRIVATE 3rdparty)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)