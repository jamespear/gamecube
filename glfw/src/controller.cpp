#include "controller.h"
#include "file.h"
#include <iostream>
#include <string>
#include <sstream>

Controller::Controller(int jid, File* f = NULL) :
            jid(jid),
            glfw_guid(glfwGetJoystickGUID(jid)),
            glfw_name(glfwGetJoystickName(jid)),
            file(f),
            file_chars(f->file_size) {
                if (f) set_mapping();
}

Controller::~Controller() {}

void Controller::set_mapping() {
    std::string mapping = (this->glfw_guid + ","
        + this->glfw_name + "," + this->file->file_contents);
    glfwUpdateGamepadMappings(mapping.c_str());
}

bool Controller::button_pressed(int button) {
    if(glfwGetGamepadState(this->jid, &state)
        && state.buttons[button] == 1) return true;
    return false;
}
