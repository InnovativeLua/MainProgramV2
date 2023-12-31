#include "main.h"
#include "custom/brain/controller.hpp"
#include "custom/mechs/intake.hpp"

void intake::opControl(){
    if (mainController.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        intakeMotor.move_velocity(100);
    } else if (mainController.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        intakeMotor.move_velocity(-100);
    }
}