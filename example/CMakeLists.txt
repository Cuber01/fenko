cmake_minimum_required(VERSION 3.5.1)

# set project name
project(fenko_example)

# add executable
add_executable(fenko_example.run main.cpp)

# set include dirs
include_directories(fenko_example.run PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib/fenko/include/)

# find and include sdl2 files
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# find and include SDL2 Mixer
include(FindPkgConfig)
pkg_check_modules(SDL2_Mixer REQUIRED IMPORTED_TARGET SDL2_mixer)
pkg_check_modules(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

# link sdl2
target_link_libraries(fenko_example.run ${SDL2_LIBRARIES} -lSDL2_image PkgConfig::SDL2_Mixer ${CMAKE_CURRENT_SOURCE_DIR}/lib/fenko/libfenko.a )
