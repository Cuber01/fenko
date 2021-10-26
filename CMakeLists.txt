cmake_minimum_required(VERSION 3.10)

# set project name
project(fenko-8)

# list source files
set(SOURCES src/main.cpp src/render.cpp src/canvas.cpp src/input.cpp src/data.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_STANDARD 14)

# add executable
add_executable(fenko-8.run ${SOURCES})

# set include dirs
include_directories(fenko-8.run PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/)

if(MSVC)
  target_compile_options(fenko-8.run PRIVATE /W4 /WX)
else()
  target_compile_options(fenko-8.run PRIVATE -Wall -Wextra -Wpedantic)
endif()

# find and include sdl2 files
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# link sdl2
target_link_libraries(fenko-8.run ${SDL2_LIBRARIES})
