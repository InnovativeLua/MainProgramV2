#pragma once
#include "main.h" //Gets the pros namespace from main.

class catapult{ //Declares a class for the catapult.
public:
    //Control types define what the catapult is doing at any point during OPControl.
    enum catapultStates {
        E_DISABLED,
        E_MANUAL,
        E_MOVING,
        E_HOLDING,
        E_AUTOFIRE
    };

    int limitDB = 0; //Debounce for the limit siwtch in ms.

    pros::Motor catapultMotor = pros::Motor(7); //Declares a motor for the catapult with port "12"
    pros::Motor liftMotor = pros::Motor(10); //Declares a motor for the lift with port "11"

    pros::ADIButton cataLimit = pros::ADIButton('G'); //Declares a limit switch object with port "F"

    int cataState = E_MANUAL; //The default state currently is manual.

    void opControl(); //Function called every time the OPControl loop is ran in main.cpp.
};

extern catapult masterCata; //Declares an extern for a global catapult object to be used across multiple files.

