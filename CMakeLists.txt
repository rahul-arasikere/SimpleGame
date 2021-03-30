cmake_minimum_required(VERSION 3.12)
project(game)

set(CMAKE_CXX_STANDARD 14)

include(ExternalProject)

ExternalProject_Add(allegro
        GIT_REPOSITORY  "https://github.com/liballeg/allegro5.git"
        GIT_TAG         "4.4"
        PREFIX          ${CMAKE_CURRENT_BINARY_DIR}/allegro
        CMAKE_ARGS      -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
)

ExternalProject_Get_Property(allegro install_dir)

include_directories(${install_dir}/include)
include_directories(include)

add_executable(game
        src/Camera.cpp
        src/Collision.cpp
        src/Enemy.cpp
        src/Map.cpp
        src/Player.cpp
        src/ScreenManager.cpp
        main.cpp
)

add_dependencies(game allegro)
target_link_directories(game PUBLIC ${install_dir}/lib)
target_link_libraries(game alleg jpgalleg loadpng alleggl)