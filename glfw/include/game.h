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

  File *file;
  Actions actions;
  char *red = new char[100 * 100 * 3];
  char *blue = new char[100 * 100 * 3];
};
