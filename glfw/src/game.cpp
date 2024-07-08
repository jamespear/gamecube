#include "game.h"
#include "file.h"

Game::Game(char const *filename) :
            filename(filename),
            file(new File(filename)){
  this->setup();
  this->loop();
}

Game::~Game() { glfwDestroyWindow(window); }

void Game::setup() {
  glfwInit();

  window = glfwCreateWindow(640, 480, "gamecube", NULL, NULL);
  for (int i = 0; i < 16; i++) {
    if (glfwJoystickPresent(i)) {
     if (glfwJoystickIsGamepad(i))
        this->controllers.push_back(Controller(i, NULL));
     else this->controllers.push_back(Controller(i, this->file));
    }
  }
  //actions = Actions(controllers);
  // actions.controller_actions(0);
  // Actions actions;
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

void Game::loop() {
  glfwMakeContextCurrent(window);
  while (!glfwWindowShouldClose(window)) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      return;
    }
    //actions.controller_actions(0);
    if (controllers[0].button_pressed(GLFW_GAMEPAD_BUTTON_X)) {
          glDrawPixels(100, 100, GL_RGB, GL_UNSIGNED_BYTE, red);
    } else if (controllers[0].button_pressed(GLFW_GAMEPAD_BUTTON_A)) {
        glDrawPixels(100, 100, GL_RGB, GL_UNSIGNED_BYTE, blue);
      // } else {
      //   glClear(GL_COLOR_BUFFER_BIT);
      //   if (glfwJoystickPresent(1)) {
      //     if (controllers[1].button_pressed("A")) {
      //       glDrawPixels(100, 100, GL_RGB, GL_UNSIGNED_BYTE, red);
      //     } else if (controllers[1].button_pressed("B")) {
      //       glDrawPixels(100, 100, GL_RGB, GL_UNSIGNED_BYTE, blue);
      //     } else {
      //       glClear(GL_COLOR_BUFFER_BIT);
      //     }
      //   }
      // }
    }
    else glClear(GL_COLOR_BUFFER_BIT);
    glfwPollEvents();
    glfwSwapBuffers(window);
  }
}
