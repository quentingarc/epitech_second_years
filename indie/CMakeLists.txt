cmake_minimum_required(VERSION 3.16)
project(bomberman)

set(CMAKE_CXX_STANDARD 14)

set(SRC 
src/Menu.cpp
src/Buttons.cpp
src/GameIntroduction.cpp
src/Splash_intro.cpp
src/Map.cpp
src/Players.cpp
main.cpp
src/Win.cpp
include/Win.hpp
include/Splash_intro.hpp
include/GameIntroduction.hpp
include/Menu.hpp
include/Buttons.hpp
include/Map.hpp
include/Players.hpp
)

add_executable(bomberman ${SRC})

target_link_libraries(bomberman raylib)

if (APPLE)
    find_package(raylib 3.0 REQUIRED)
    target_link_libraries(bomberman "-framework IOKit")
    target_link_libraries(bomberman "-framework Cocoa")
    target_link_libraries(bomberman "-framework OpenGL")
endif()