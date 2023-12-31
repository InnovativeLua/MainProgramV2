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

    pros::Motor catapultMotor = pros::Motor(9);
    pros::Motor liftMotor = pros::Motor(9);

    pros::ADIButton cataLimit = pros::ADIButton('A');

    int cataState = E_MANUAL;

    void opControl();
};