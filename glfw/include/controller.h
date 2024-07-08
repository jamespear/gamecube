#pragma once
#include "file.h"
#include "glfw3.h"
#include <map>
#include <vector>
#include <string>

class Controller {
public:
  Controller(int jid, File* f);
  ~Controller();

  void set_mapping();
  bool button_pressed(int button);

  int jid;
  File* file;

  GLFWgamepadstate state;
  std::string glfw_guid;
  std::string glfw_name;
  long file_chars;
  int n;
};
