cmake_minimum_required(VERSION 3.20)
project(MateROV LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tell CMake where Home-brew put SDL2
# (HOMEBREW_PREFIX expands to /opt/homebrew on Apple-Silicon,
#  /usr/local on Intel.)
list(APPEND CMAKE_PREFIX_PATH "$ENV{HOMEBREW_PREFIX}/opt/sdl2")

find_package(SDL2 CONFIG REQUIRED)          # ← use the brew-supplied config

list(APPEND CMAKE_PREFIX_PATH "$ENV{HOMEBREW_PREFIX}/opt/sdl2_ttf")
find_package(SDL2_ttf CONFIG REQUIRED)

add_executable(MateROV main.cpp
        Visual.cpp
        Visual.h
)

# Disable SDL’s “replace main” macro so we don’t need SDL2main
target_compile_definitions(MateROV PRIVATE SDL_MAIN_HANDLED)

# Link with the imported targets defined by the config file
target_link_libraries(MateROV PRIVATE
                        SDL2::SDL2
                        SDL2_ttf::SDL2_ttf)                 # if you LEAVE the macro above out:
# also add SDL2::SDL2main here
