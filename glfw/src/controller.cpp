#include "controller.h"
#include <stdio.h>
#include <stdlib.h>

Controller::Controller(int jid)
    : jid(jid), name(glfwGetJoystickName(jid)) {
       set_mapping();
   }

Controller::~Controller() {
    mapping.clear();
}

void Controller::set_mapping() {
    // FILE *fp = fopen("../gamecontrollerdb.txt", "r");
    // char buffer[file_chars];
    // while (!feof(fp)) {
    //     fread(buffer, sizeof(buffer), 1, fp);
    // }
    // fclose(fp);
    // printf("%s\n", buffer);
    mapping["y"] = 0;
    mapping["b"] = 1;
    mapping["a"] = 2;
    mapping["x"] = 3;
    mapping["lt"] = 4;
    mapping["rt"] = 5;
    mapping["zl"] = 6;
    mapping["-"] = 8;
    mapping["+"] = 9;
    mapping["home"] = 12;
    mapping["pause"] = 13;
    mapping["d-pad u"] = 14;
    mapping["d-pad r"] = 15;
    mapping["d-pad d"] = 16;
    mapping["d-pad l"] = 17;
}

bool Controller::button_pressed(std::string button) {
    return glfwGetJoystickButtons(jid, &n)
    [mapping[button]];
}
