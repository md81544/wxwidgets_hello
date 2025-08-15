cmake_minimum_required(VERSION 3.20)
project(hello LANGUAGES CXX)

# Require C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find wxWidgets (adjust components if you need more)
find_package(wxWidgets REQUIRED COMPONENTS core base)

# Include wxWidgets headers
include(${wxWidgets_USE_FILE})

# Create the executable
add_executable(hello main.cpp)

# Link wxWidgets libraries
target_link_libraries(hello PRIVATE ${wxWidgets_LIBRARIES})
