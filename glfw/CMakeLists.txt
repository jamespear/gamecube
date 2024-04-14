cmake_minimum_required(VERSION 3.5)

project(game)

include_directories(include)

find_package(glfw3)
include_directories(/usr/local/include/GLFW)


add_compile_definitions(JUCE_SILENCE_XCODE_15_LINKER_WARNING=1)
add_subdirectory(JUCE)
include_directories(JUCE/modules)

#juce_add_module(JUCE/modules/juce_core)

file(GLOB src src/*.cpp)

add_executable(game ${src})

target_link_libraries(game glfw "-framework OpenGL")

target_link_libraries(game juce_core "-Wl -ld_classic")
target_link_libraries(game juce_osc "-Wl -ld_classic")
