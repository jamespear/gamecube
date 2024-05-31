#include "actions.h"

Actions::Actions() {}

Actions::~Actions() {}

Actions::Actions(std::vector<Controller> &controllers)
    : controllers(controllers) {
  for (int y = 0; y < 100; y++) {
    for (int x = 0; x < 100; x++) {
      red[y * 100 * 3 + x * 3] = 0xff;
      red[y * 100 * 3 + x * 3 + 1] = 0x00;
      red[y * 100 * 3 + x * 3 + 2] = 0x00;
      blue[y * 100 * 3 + x * 3] = 0x00;
      blue[y * 100 * 3 + x * 3 + 1] = 0x00;
      blue[y * 100 * 3 + x * 3 + 2] = 0xff;
    }
  }
}

void Actions::controller_actions(int jid) {
  if (glfwJoystickPresent(0)) {
    if (controllers[0].button_pressed("a")) {
      glDrawPixels(100, 100, GL_RGB, GL_UNSIGNED_BYTE, red);
    } else if (controllers[0].button_pressed("b")) {
      glDrawPixels(100, 100, GL_RGB, GL_UNSIGNED_BYTE, blue);
    } else {
      glClear(GL_COLOR_BUFFER_BIT);
      if (glfwJoystickPresent(1)) {
        if (controllers[1].button_pressed("a")) {
          glDrawPixels(100, 100, GL_RGB, GL_UNSIGNED_BYTE, red);
        } else if (controllers[1].button_pressed("b")) {
          glDrawPixels(100, 100, GL_RGB, GL_UNSIGNED_BYTE, blue);
        } else {
          glClear(GL_COLOR_BUFFER_BIT);
        }
      }
    }
  }
}
