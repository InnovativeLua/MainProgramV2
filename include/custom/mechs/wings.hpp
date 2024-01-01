#pragma once

#include "main.h"

class wings{
public:
    enum wingType {
        E_WINGTYPE_ENABLED,
        E_WINGTYPE_DISABLED,
    };

    const int totalCooldownTime = 200;

    int wingsTimeElapsed;
    bool cooldown;

    int wingsState;

    void enableWings();

    void disableWings();

    void opControl(int driveTimeElapsed);

    void initilize();

    pros::ADIDigitalOut wingsPiston1 = pros::ADIDigitalOut('A');
    pros::ADIDigitalOut wingsPiston2 = pros::ADIDigitalOut('B');
};

extern wings masterWings;