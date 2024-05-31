#include "controller.h"
#include "file.h"
#include <cstdio>
#include <cstring>

Controller::Controller(int jid, File* f) :
            jid(jid),
            glfw_name(glfwGetJoystickName(jid)),
            file(f),
            file_chars(f->file_size) {
  set_mapping();
}

Controller::~Controller() { mapping.clear(); }

void Controller::set_mapping() {
  sscanf(this->file->file_contents, "%s%n", this->mapping_name, &n);
  const char *type;
  const char *specifier;
  int i = 0;
  this->file->file_contents += n;
  while (sscanf(this->file->file_contents, "%s %s%n", type, specifier, &n) > 0) {
      if (strcmp(type, "Button") == 0) {
          mapping[specifier] = i;
      } else if (strcmp(type, "D-Pad") == 0) {
          mapping[specifier] = i;
      } else if (strcmp(type, "Trigger") == 0) {
          mapping[specifier] = i;
      } else if (strcmp(type, "Control") == 0) {

      } else if (strcmp(type, "C-Stick")) {

      }
      this->file->file_contents += n;
      i++;
  }
}

bool Controller::button_pressed(const char *button) {
  return glfwGetJoystickButtons(jid, &n)[mapping[button]];
}
