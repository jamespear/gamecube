#pragma once
#include "file.h"
#include "glfw3.h"
#include <map>
#include <vector>

class Controller {
public:
  Controller(int jid, File* f);
  ~Controller();

  void set_mapping();
  bool button_pressed(const char *button);

  int jid;
  File* file;

  const char *glfw_name;
  const char *mapping_name;
  std::map<const char *, int> mapping;
  long file_chars;
  int n;
};
