cmake_minimum_required(VERSION 3.27)
project(Note)

set(CMAKE_CXX_STANDARD 17)




set(CMAKE_CXX_STANDARD_REQUIRED True)




add_executable(Note main.cpp
        Note.cpp
        Note.h
        Date.cpp
        Date.h
        Raccoglitore.cpp
        Raccoglitore.h
        Cartella.cpp
        Cartella.h
)
