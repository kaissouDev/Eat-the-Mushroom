add_subdirectory(raylib)
add_subdirectory(fmt)

# Create a shared library for 3rdparty
add_library(3rdparty INTERFACE)

# Link library
target_link_libraries(3rdparty INTERFACE 
    raylib
    fmt
)

