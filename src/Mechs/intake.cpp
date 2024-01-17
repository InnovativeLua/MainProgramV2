#include "main.h"
#include "custom/brain/controller.hpp"
#include "custom/mechs/intake.hpp"

void intake::opControl(){
    if (mainController.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        spinForward();
    } else if (mainController.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        spinReverse();
    } else {
        stop();
    }
}

void intake::spinForward(){
    intakeMotor.move_velocity(100);
}

void intake::spinReverse(){
    intakeMotor.move_velocity(-100);
}

void intake::stop(){
    intakeMotor.move_velocity(0);
}

intake masterIntake;