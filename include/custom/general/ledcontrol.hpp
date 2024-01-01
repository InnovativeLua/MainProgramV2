#pragma once
#include "main.h"
class ledcontroller{
    sylib::Addrled addrled = sylib::Addrled(0,0,64);

    void initialize();
    void defaultColor();
};