# CMakeLists.txt generated from blmake.lua!

# Minimum CMake version
cmake_minimum_required(VERSION 3.14)

# Project metadata
project(main VERSION 0.0.1)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Compiler options
set(CMAKE_CXX_COMPILER "g++")

# Include directories
include_directories(
    /Users/benlandrette/Qt/6.8.1/macos/lib/QtWidgets.framework 
    /Users/benlandrette/Qt/6.8.1/macos/lib/QtWidgets.framework/Headers 
    /Users/benlandrette/Qt/6.8.1/macos/lib/QtGui.framework/Headers 
    /Users/benlandrette/Qt/6.8.1/macos/lib/QtCore.framework/Headers
)

# Source files
set(SOURCE_FILES
	main.cpp
    gui.cpp
)

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out)

# Compilation flags
set(COMPILATION_FLAGS "")
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    list(APPEND COMPILATION_FLAGS "-g")
endif()

# Add executable
add_executable(main ${SOURCE_FILES})

# Apply compilation flags
target_compile_options(main PRIVATE ${COMPILATION_FLAGS})

# Add framework path to cmake prefix path
set(CMAKE_PREFIX_PATH "/Users/benlandrette/Qt/6.8.1/macos")

# Find required package 
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# Link libraries
target_link_libraries(main PRIVATE 
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

# Custom linker paths
link_directories(${CMAKE_SOURCE_DIR}/)
