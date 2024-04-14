#include "controller.h"
class Game {
public:
  Game();
  ~Game();
  void setup();
  void loop();

  static void joystick_init(int jid, int event);

  GLFWwindow *window;
  int num_controllers;
  std::vector<GLFWgamepadstate> gamepad;
  std::vector<Controller> controllers;
  inline static std::vector<bool> is_connected_controller = std::vector<bool>(16, false);
  char* red = new char[100*100*3];
  char* blue = new char[100*100*3];
};