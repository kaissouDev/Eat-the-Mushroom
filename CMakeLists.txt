cmake_minimum_required(VERSION 3.8)
project(Eat-The-Mushroom CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_GENERATOR "Ninja" CACHE INTERNAL "CMake generator" FORCE)


# Set CPack configuration
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

# Set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Include testing
include(CTest)
enable_testing()

# Add subdirectory for 3rd party library
add_subdirectory(3rdparty)

# Create the executable target
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/init.cpp
)

# Link the 3rdparty library to the executable target
target_link_libraries(${PROJECT_NAME} PRIVATE 3rdparty)

# Copy font and res directories to the appropriate build directory
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:${PROJECT_NAME}>/font"
    COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:${PROJECT_NAME}>/res"
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/font" "$<TARGET_FILE_DIR:${PROJECT_NAME}>/font"
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/res" "$<TARGET_FILE_DIR:${PROJECT_NAME}>/res"
)

# Configure build system for Ninja

