#pragma once

class intake{
public:
    pros::Motor intakeMotor = pros::Motor(8);

    void intake::spinForward();

    void intake::spinReverse();

    void intake::stop();

    void opControl();
};

extern intake masterIntake;