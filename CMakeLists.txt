cmake_minimum_required(VERSION 3.25)
project(solar_system)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        solar_system
        main.cpp
        celestial.h
        drawable.h
        moveable.h
        color.h
        point.cpp
        color.cpp
        utils.cpp
        drawable.cpp
        celestial.cpp
        moveable.cpp
        solar_system.h particle.h particle.cpp solar_system.cpp buffer.h buffer.cpp fps_counter.h fps_counter.cpp)

target_link_libraries(solar_system -lOpenGL32 -lfreeGLUT)
