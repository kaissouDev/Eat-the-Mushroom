add_subdirectory(raylib)
add_subdirectory(fmt)
add_subdirectory(Boxer)

# Create a shared library for 3rdparty
add_library(3rdparty INTERFACE)

# Link library
target_link_libraries(3rdparty INTERFACE 
    raylib
    fmt
    Boxer
)

if (WIN32)
   target_compile_definitions(Boxer PRIVATE UNICODE)
endif (WIN32)
