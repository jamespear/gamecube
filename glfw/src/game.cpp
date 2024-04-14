#include "game.h"

Game::Game() {
  this->setup();
  this->loop();
}

Game::~Game() { glfwDestroyWindow(window); }

void Game::setup() {
  glfwInit();
  window = glfwCreateWindow(640, 480, "gamecube", NULL, NULL);
  glfwSetJoystickCallback(joystick_init);
  for (int i = 0; i < 16; i++) {
      if (glfwJoystickPresent(i)) {
          controllers.push_back(Controller(i));
      }
  }
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
    if (controllers[0].button_pressed("a")) {
        printf("%s", "bruh");
        //glDrawPixels(100, 100, GL_RGB, GL_UNSIGNED_BYTE, red);
    }
    if (controllers[0].button_pressed("b")) {
        printf("%s", "bruh2");
        //glDrawPixels(100, 100, GL_RGB, GL_UNSIGNED_BYTE, blue);
    }
    glfwPollEvents();
    //glDrawPixels(100, 100, GL_RGB, GL_UNSIGNED_BYTE, red);
    //glfwSwapBuffers(window);
    //glfwWaitEvents();
  }
}

void Game::joystick_init(int jid, int event) {
    if (event == GLFW_CONNECTED) {
       is_connected_controller[jid] = true;
       printf("Controller %s connected!", glfwGetJoystickName(jid));
    } else {
        printf("Controller %s disconnected", glfwGetJoystickName(jid));
    }
}
