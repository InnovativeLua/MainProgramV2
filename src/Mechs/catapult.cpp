#include "custom/mechs/catapult.hpp"
#include "custom/brain/controller.hpp"

void catapult::opControl(){
    switch(cataState) {
    case E_MANUAL:
    
        catapultMotor.move_velocity(100);
        break;
    case E_HOLDING:
        if (mainController.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
            catapultMotor.move_velocity(50);
            cataState = E_MOVING;
            limitDB = 0;
        }

        break;
    case E_MOVING:
        if (cataLimit.get_value() && (limitDB > 100)){
            cataState = E_HOLDING;
            catapultMotor.move_velocity(0);
        } else {
            catapultMotor.move_velocity(50);
        }

        break;
    case E_AUTOFIRE:
 
        break;

    limitDB += 10;
    }
    if (mainController.get_digital(pros::E_CONTROLLER_DIGITAL_UP)){
        liftMotor.move_velocity(100);
    } else if (mainController.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){
        liftMotor.move_velocity(-100);
    }
}

catapult masterCata;