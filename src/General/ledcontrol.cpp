#include "custom/general/ledcontrol.hpp"

void ledcontroller::defaultColor(){
    addrled.gradient(0xFF0000, 0xFF0005, 0, 0, false, true);
}

void ledcontroller::initialize(){
    addrled.set_all(0xE62169);
}

ledcontroller masterLED;