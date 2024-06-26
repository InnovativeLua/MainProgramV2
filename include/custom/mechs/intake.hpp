#pragma once

class intake{
public:

    //Control types define what the intake is doing at any point during OPControl.
    enum intakeStates {
        E_DISABLED,
        E_MANUAL,
        E_IDLE,
        E_INTAKING,
        E_OUTTAKING
    };

    int intakeState = E_MANUAL; //The default state currently is manual.

    int toggleDB = 0; //Debounce for the toggle in ms.

    void spinForward(); //Function when called spins the intake forward.

    void spinReverse(); //Function when called spins the intake reverse.

    void stop(); //Function when called stops the intake from moving.

    void opControl(); //Function called every time the OPControl loop is ran in main.cpp.

    pros::Motor intakeMotor = pros::Motor(8); //Declares a motor for the catapult with port "8"
};

extern intake masterIntake; //Global intake object to be accessed by any files.

