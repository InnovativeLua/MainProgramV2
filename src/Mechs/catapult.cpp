#include "custom/mechs/catapult.hpp"
#include "custom/brain/controller.hpp"

void catapult::opControl(){
    switch(cataState) { //Looks at the different states the catapult can be in.
    case E_MANUAL: //If the catapult is in manual state, part of the manual control system.
        if (mainController.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && mainController.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){ 
            //Looks to see if the controller is being pressed both L1 and L2 which is a macro to switch state to automatic fire.
            cataState = E_AUTOFIRE; //Switches the state to autofiring mode.
            break; //Prevents the rest of the code from running.
        }
        if (mainController.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){ //Looks for the press of L1 on the controller.
            catapultMotor.move_velocity(100); //Moves the catapult forwards.
        } else if (mainController.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){ //Looks for the press of L2 on the controller.
            catapultMotor.move_velocity(-100); //Moves the catapult backwards.
        } else {
            catapultMotor.move_velocity(0); //Stops the catapult.
        }

        if (mainController.get_digital(pros::E_CONTROLLER_DIGITAL_B)){ //Looks for the press of B on the controller.
            cataState = E_MANUAL; //Switches the catapult state to manual.
        }
        break; //Closes the switch statement.
    case E_HOLDING: //If the catapult is in the holding state, part of the automatic control system.
        if (mainController.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){ //Looks for the press of L1 on the controller.
            catapultMotor.move_velocity(50); //Moves the catapult forward at 50% speed.
            cataState = E_MOVING; //Sets the catapult state to moving.
            limitDB = 0; //Resets the debounce for the limit switch.
        } else if (mainController.get_digital(pros::E_CONTROLLER_DIGITAL_A)){ //Looks for the press of A on the controller.
            cataState = E_MANUAL;  //Sets the catapult state to manual.
        } 
        break; //Closes the switch statement.
    case E_MOVING: //If the catapult is in the moving state, part of the automatic control system.
        if (cataLimit.get_value() && (limitDB > 100)){ //Checks if the limit switch is being pressed and the debounce is inactive.
            cataState = E_HOLDING; //Sets catapult state to holding.
            catapultMotor.move_velocity(0); //Stops the catapult motor from moving.
        } else {
            catapultMotor.move_velocity(50); //Moves the catapult motor forwards.
        }
        break; //Closes the switch statement.
    case E_AUTOFIRE: //If the catapult is in the autofire state, part of the manual control system.
        if (mainController.get_digital(pros::E_CONTROLLER_DIGITAL_L1) || mainController.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
            //Checks if the controller L1 or L2 buttons are being pressed which interupts the autofiring process.
            cataState = E_MANUAL; //Sets the state back to manual.
            break; //Stops the catapult motor from being moved.
        }
        catapultMotor.move_velocity(100); //Moves the catapult forward if both L1 or L2 are not being pressed.
        break; //Closes the switch statement.

    limitDB += 10; //Adds 10ms to the limit debounce. OPControl loop runs every 10ms.
    }
    if (mainController.get_digital(pros::E_CONTROLLER_DIGITAL_UP)){ //Looks for the press of Up on the controller.
        liftMotor.move_velocity(100); //Moves the lift up.
    } else if (mainController.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){ //Looks for the press of Down on the controller.
        liftMotor.move_velocity(-100); //Moves the lift down.
    }
}

catapult masterCata; //Declares a global masterCata to be used across multiple files.

