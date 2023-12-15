#pragma once
#include "main.h"

class catapult{
public:

    //Control types are for driver control period
    enum catapultControlTypes {
        E_MANUALRETRACT,
        E_AUTORETRACT
    };

    enum catapultPositions {
        E_LOADED,
        E_MOVING_UP,
        E_MOVING_DOWN,
        E_UNLOADED
    };
    catapult();

    pros::Motor catapultMotor = pros::Motor(0);

    int cataPosition;
    int catapultControlType; 

    void opControl();

    catapult::catapult(int cataport);

};