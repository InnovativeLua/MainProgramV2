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

    pros::Motor catapultMotor = pros::Motor(19); //Declares a motor for the catapult with port "7"
    pros::Motor catapultMotor2 = pros::Motor(20, true); //Declares a motor for the catapult with port "7"

    pros::ADIDigitalOut liftPistons = pros::ADIDigitalOut('C'); //Pnemautic cylinder object / right wing in the A port.

    pros::ADIButton cataLimit = pros::ADIButton('G'); //Declares a limit switch object with port "G"

    int cataState = E_MANUAL; //The default state currently is manual.

    void opControl(); //Function called every time the OPControl loop is ran in main.cpp.
};

extern catapult masterCata; //Declares an extern for a global catapult object to be used across multiple files.

