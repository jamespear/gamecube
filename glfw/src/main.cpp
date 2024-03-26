#include "glfw3.h"
#include "juce_core/juce_core.h"
/*
#include "JUCE/modules/juce_core/juce_core.h"
#include <juce_core/juce_core.cpp>
#include <juce_data_structures/juce_data_structures.cpp>
#include <juce_events/juce_events.cpp>
#include <juce_graphics/juce_graphics.cpp>
#include <juce_basics/juce_basics.cpp>
#include <juce_gui_extra/juce_gui_extra.cpp>
#include <juce_core/juce_core.h>
*/

int main() {
    printf("%d", glfwJoystickPresent(GLFW_JOYSTICK_1));
    return 0;
}
