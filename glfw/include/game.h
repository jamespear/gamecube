#include "actions.h"
#include "controller.h"

class Game {
public:
  Game(const char *filename);
  ~Game();
  void setup();
  void loop();

  static void joystick_init(int jid, int event);

  GLFWwindow *window;
  int num_controllers;
  std::vector<GLFWgamepadstate> gamepad;
  std::vector<Controller> controllers;

  const char *filename;

  Actions action;
};
