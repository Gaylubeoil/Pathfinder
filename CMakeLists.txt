cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

# Set project name and version
project(Pathfinder VERSION 0.1)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Enable debug symbols by default
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug
    CACHE STRING
    "Choose the type of build (Debug or Release)"
    FORCE
  )
endif()

# Find SFML shared libraries
find_package(SFML 2.5
  COMPONENTS
  system window graphics network audio REQUIRED
)

# Set source files directory
set(SOURCE_DIR
  src/main.cpp
  src/Application.cpp
  src/Maze.cpp
  src/Editor.cpp
  src/Utility.cpp
  src/Cell.cpp
)

# Compile executable
add_executable(${PROJECT_NAME} ${SOURCE_DIR})

# Set include directory search paths
target_include_directories(Pathfinder
  PRIVATE
  "${PROJECT_BINARY_DIR}"
)
target_include_directories(${PROJECT_NAME} PRIVATE
  Include/
)

# Link executable to required SFML libraries
target_link_libraries(Pathfinder sfml-graphics)

# Install target
install(TARGETS Pathfinder DESTINATION bin)