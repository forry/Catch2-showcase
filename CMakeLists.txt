cmake_minimum_required(VERSION 3.15)
cmake_policy(VERSION 3.15)

project(Tests
    VERSION 0.0.0
    LANGUAGES CXX)
    
set(CMAKE_CONFIGURATION_TYPES "Release;Debug" CACHE STRING "" FORCE)

include(${CMAKE_BINARY_DIR}/conanbuildinfo_multi.cmake)
include(CTest)

conan_basic_setup(TARGETS)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "_cmake")

add_executable(TestApp)
target_sources(TestApp
    PRIVATE
        TestApp/main.cpp
        TestApp/SomeClass.h TestApp/SomeClass.cpp
)

target_include_directories(TestApp PRIVATE TestApp)

add_library(TestLib)

target_sources(TestLib
    PUBLIC
        TestLib/LibClass.h
    PRIVATE
        TestLib/LibClass.cpp
)
target_include_directories(TestLib PUBLIC TestLib)

add_executable(tests)

target_sources(tests
    PRIVATE
        tests/TestApp/main.cpp
        tests/TestApp/test1.cpp
        tests/TestApp/test2.cpp 
        TestApp/SomeClass.cpp
)
target_link_libraries(tests CONAN_PKG::catch2)
target_include_directories(tests PRIVATE TestApp)
set_target_properties(tests PROPERTIES FOLDER "Unit Tests")

add_executable(tests_TestLib)
target_sources(tests_TestLib
    PRIVATE
        tests/TestLib/main.cpp
        tests/TestLib/test_get_set.cpp
)
target_link_libraries(tests_TestLib CONAN_PKG::catch2 TestLib)
set_target_properties(tests_TestLib PROPERTIES FOLDER "Unit Tests")

#### CTEST ####

add_test(NAME tests COMMAND tests)
add_test(NAME tests_TestLib COMMAND tests_TestLib)

set_directory_properties(PROPERTIES VS_STARTUP_PROJECT TestApp)