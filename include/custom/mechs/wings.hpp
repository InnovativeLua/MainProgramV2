#pragma once

#include "main.h"

class wings{ //Class to hold the wings.
public:
    enum wingType { //Different states the wings can be in.
        E_WINGTYPE_ENABLED, //Enabled / Extended
        E_WINGTYPE_DISABLED, //Disabled / Retracted
    };

    const int totalCooldownTime = 500; //Total time to wait between button presses.

    int wingsTimeElapsed; //Time the cooldown has been running.
    bool cooldown; //Cooldown/Debounce is active or not.

    int wingsState; //The state the wings are in.

    void enableWings(); //Function to enable and extend the wings.

    void disableWings(); //Function to disabled and retract the wings.

    void opControl(int driveTimeElapsed); //Main operator control loop. driveTimeElapsed is amount of time between operator loops.

    void initilize(); //Initalizes the wings, ran in the initalization stage.

    pros::ADIDigitalOut wingsPiston1 = pros::ADIDigitalOut('B'); //Pnemautic cylinder object / right wing in the A port.
};

extern wings masterWings; //Global wings object to be assessed from other files.


