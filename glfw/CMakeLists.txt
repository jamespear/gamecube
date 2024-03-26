cmake_minimum_required(VERSION 3.5)

project(game)

add_subdirectory(glfw-3.4)
include_directories(glfw-3.4/include/GLFW)

add_subdirectory(JUCE)
include_directories(JUCE/modules)

#juce_add_module(JUCE/modules/juce_core)

add_executable(game src/main.cpp)

target_link_libraries(game glfw)

target_link_libraries(game juce_core "-Wl -ld_classic")
target_link_libraries(game juce_osc "-Wl -ld_classic")
