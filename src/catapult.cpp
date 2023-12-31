#include "catapult.hpp"
pros::Controller mainController2(CONTROLLER_MASTER);

void catapult::opControl(){
    switch(cataState) {
    case E_MANUAL:
        // code block
        catapultMotor.move_velocity(100);
        break;
    case E_HOLDING:
        if (mainController2.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
            catapultMotor.move_velocity(50);
            cataState = E_MOVING;
            limitDB = 0;
        }
        // code block
        break;
    case E_MOVING:
        if (cataLimit.get_value() && (limitDB > 100)){
            cataState = E_HOLDING;
            catapultMotor.move_velocity(0);
        } else {
            catapultMotor.move_velocity(50);
        }
        // code block
        break;
    case E_AUTOFIRE:
        // code block
        break;

    limitDB += 10;
    }
}