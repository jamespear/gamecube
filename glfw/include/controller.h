#include <map>
#include <vector>
#include <string>
#include "glfw3.h"

class Controller {
public:
  Controller(int jid);
  ~Controller();

  void set_mapping();
  bool button_pressed(std::string button);

  int jid;
  std::string name;
  std::map<std::string, int> mapping;
  int file_chars = 172; //bit of a kludge
  int *num_buttons;
};
