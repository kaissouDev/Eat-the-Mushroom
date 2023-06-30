# RunCommand from build -> cmake -DBUILD_SHARED_LIBS=FALSE -G Ninja ..

cmake_minimum_required(VERSION 3.20)
project(Eat-The-Mushroom CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set CPack configuration
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

# Set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

if(MINGW)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
endif()
if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()


add_subdirectory(3rdparty)

# Create the executable target
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/game.cpp
)

# Link the 3rdparty library to the executable target
target_link_libraries(${PROJECT_NAME} PRIVATE 3rdparty)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall)