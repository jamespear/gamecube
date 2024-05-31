#include "game.h"
#include "file.h"

Game::Game(char const *filename) : filename(filename) {
  this->setup();
  this->loop();
}

Game::~Game() { glfwDestroyWindow(window); }

void Game::setup() {
  glfwInit();
  window = glfwCreateWindow(640, 480, "gamecube", NULL, NULL);
  for (int i = 0; i < 16; i++) {
    if (glfwJoystickPresent(i)) {
      File f(this->filename);
      controllers.push_back(Controller(i, &f));
    }
  }
  // actions = Actions(controllers);
  // actions.controller_actions(0);
  // Actions actions;
}

void Game::loop() {
  glfwMakeContextCurrent(window);
  while (!glfwWindowShouldClose(window)) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      return;
    }
    glfwPollEvents();
    glfwSwapBuffers(window);
  }
}
