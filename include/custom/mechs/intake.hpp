#pragma once

class intake{
public:
    pros::Motor intakeMotor = pros::Motor(8);



    void opControl();
};

extern intake masterIntake;