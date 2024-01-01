#pragma once

class intake{
public:
    pros::Motor intakeMotor = pros::Motor(9);



    void opControl();
};

extern intake masterIntake;