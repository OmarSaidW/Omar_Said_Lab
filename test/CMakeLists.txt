cmake_minimum_required(VERSION 3.12)

set(GOOGLETEST_VERSION 1.15.2)
add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(/test)

set(TEST_SOURCE_FILES RaccoglietoreFixture.cpp
        ClassTest.cpp
        runAllTest.cpp
)
add_executable(runNoteTests ${TEST_SOURCE_FILES})
target_link_libraries(runNoteTests gtest gtest_main core)
