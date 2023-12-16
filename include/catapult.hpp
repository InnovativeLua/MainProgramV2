#pragma once
#include "main.h"

class catapult{
public:

    //Control types are for driver control period
    enum catapultStates {
        E_DISABLED,
        E_MANUAL,
        E_MOVING,
        E_HOLDING,
        E_AUTOFIRE
    };

    int limitDB = 0;

    catapult();

    pros::Motor catapultMotor = pros::Motor(0);

    pros::ADIButton cataLimit = pros::ADIButton(0);

    int cataState = E_MANUAL;

    void opControl();

    catapult(int cataport, int limitPort);

};