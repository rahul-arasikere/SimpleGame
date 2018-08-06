cmake_minimum_required(VERSION 3.12)
project(Game)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(enemy)
include_directories(include)
include_directories(levels)
include_directories(media)
include_directories(src)

add_executable(Game
        enemy/Enemy.txt
        include/Camera.h
        include/Collision.h
        include/Enemy.h
        include/Global.h
        include/Map.h
        include/Player.h
        include/ScreenManager.h
        levels/ColMap1.txt
        levels/ColMap2.txt
        levels/ColMap3.txt
        levels/Map1.txt
        levels/Map2.txt
        levels/Map3.txt
        media/gameover.bmp
        media/ground.bmp
        media/stone.bmp
        media/title.bmp
        src/Camera.cpp
        src/Collision.cpp
        src/Enemy.cpp
        src/Map.cpp
        src/Player.cpp
        src/ScreenManager.cpp
        main.cpp
        README.md)

