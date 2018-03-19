cmake_minimum_required(VERSION 3.8)
project(LaFourmilliere)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_FLAGS -m64)
set(CMAKE_CXX_FLAGS -m64)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")


set(SOURCE_FILES main.cpp test.cpp test.h Map.cpp Map.h Queen.cpp Queen.h Entity.cpp Entity.h Entity.cpp Entity.h Water.cpp Water.h Food.cpp Food.h Worker.cpp Worker.h Warrior.cpp Warrior.h Seed.cpp Seed.h IEntity.cpp IEntity.h)
add_executable(LaFourmilliere ${SOURCE_FILES})
