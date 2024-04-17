#pragma once
#include "main.h"
class ledcontroller{
public:
    sylib::Addrled addrled = sylib::Addrled(22,'C',64);

    void initialize();
    void defaultColor();
};

extern ledcontroller masterLED;