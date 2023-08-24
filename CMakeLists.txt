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
        observer.h
        observer.cpp
        drawable.cpp
        celestial.cpp
        moveable.cpp
)

target_link_libraries(solar_system -lOpenGL32 -lfreeGLUT)
