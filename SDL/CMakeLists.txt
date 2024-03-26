cmake_minimum_required(VERSION 3.5)

project(game)

add_subdirectory(SDL2)
include_directories(SDL2/include)

#find_package(SDL2 CONFIG REQUIRED)
#include_directories(${SDL2_INCLUDE_DIRS})

add_subdirectory(JUCE)
include_directories(JUCE/modules)

#juce_add_module(JUCE/modules/juce_core)

#target_sources(game main.cpp)

add_executable(game main.cpp)


target_link_libraries(game SDL2)

#target_link_libraries(game juce::juce_core)

#target_link_libraries(game ${SDL2_LIBRARIES})

target_link_libraries(game juce_core)
target_link_libraries(game juce_osc)
