# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(CodeEditor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source directories
include_directories(src)

# Add subdirectories for building
add_subdirectory(src/core)
add_subdirectory(src/editor)
add_subdirectory(src/ui/desktop)

# Create the executable
add_executable(CodeEditor main.cpp)

# Link necessary libraries (e.g., Qt)
find_package(Qt6 COMPONENTS Widgets REQUIRED)
target_link_libraries(CodeEditor PRIVATE Qt6::Widgets)
