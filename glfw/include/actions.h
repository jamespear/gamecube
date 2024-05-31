#pragma once
#include "controller.h"
#include <vector>
class Actions {
public:
  Actions();
  Actions(std::vector<Controller> &controllers);
  ~Actions();

  void controller_actions(int jid);

  char *red = new char[100 * 100 * 3];
  char *blue = new char[100 * 100 * 3];
  std::vector<Controller> controllers;
};
