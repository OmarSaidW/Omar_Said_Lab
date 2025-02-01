cmake_minimum_required(VERSION 3.27)
project(Note)

set(CMAKE_CXX_STANDARD 17)




set(CMAKE_CXX_STANDARD_REQUIRED True)




add_executable(Note
        Note.h
        Raccoglitore.cpp
        Raccoglitore.h
        Cartella.cpp
        Cartella.h
        wx.cpp
)
add_subdirectory(test)

set(SOURCE_FILES
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