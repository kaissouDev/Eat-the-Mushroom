cmake_minimum_required(VERSION 3.8)
project(Eat-The-Mushroom CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Set CPack configuration
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

# Set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Include testing
#include(CTest)
#enable_testing()

# Add subdirectory for 3rd party library
if(MINGW)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
endif()

add_subdirectory(3rdparty)

# Create the executable target
add_executable(${PROJECT_NAME}
    src/main.cpp
)

# Link the 3rdparty library to the executable target
target_link_libraries(${PROJECT_NAME} PRIVATE 3rdparty)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall)