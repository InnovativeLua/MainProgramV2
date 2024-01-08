#pragma once
#include "main.h"
class ledcontroller{
    sylib::Addrled addrled = sylib::Addrled(20,20,64);

    void initialize();
    void defaultColor();
};