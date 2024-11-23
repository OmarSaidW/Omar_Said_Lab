cmake_minimum_required(VERSION 3.27)
project(Note)

set(CMAKE_CXX_STANDARD 17)




set(CMAKE_CXX_STANDARD_REQUIRED True)




add_executable(Note main.cpp
        Note.cpp
        Note.h
        Raccoglitore.cpp
        Raccoglitore.h
        Cartella.cpp
        Cartella.h
        Observer.h
        Subject.h
        Model.cpp
        Model.h
        Controller.cpp
        Controller.h
        View.cpp
        View.h
)
add_subdirectory(test)

set(SOURCE_FILES Note.cpp
        Note.h
        Raccoglitore.cpp
        Raccoglitore.h
        Cartella.cpp
        Cartella.h)

add_library(core ${SOURCE_FILES})
target_link_libraries(Note core)
find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})


target_link_libraries(Note ${wxWidgets_LIBRARIES})