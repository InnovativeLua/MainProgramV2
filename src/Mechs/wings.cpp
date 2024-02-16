#include "custom/mechs/wings.hpp"
#include "custom/brain/controller.hpp"

void wings::enableWings(){ //Function which sets the wings to enabled and extends the pneumatic cylinders.
    wingsPiston1.set_value(true); //Sets right piston to extend.
    wingsPiston2.set_value(true); //Sets left piston to extend.
    wingsState = E_WINGTYPE_ENABLED; //Updates the state of the wings to enabled.
}

void wings::disableWings(){ //Function which sets the wings to disabled and retracts the pneumatic cylinders.
    wingsPiston1.set_value(false); //Sets right piston to retract.
    wingsPiston2.set_value(false); //Sets left piston to retract.
    wingsState = E_WINGTYPE_DISABLED; //Updates the state of the wings to disabled.
}

//Main operator control loop. driveTimeElapsed is amount of time between operator loops.
void wings::opControl(int driveTimeElapsed){
    if (cooldown){ //Only runs if a cooldown is active.
        wingsTimeElapsed += driveTimeElapsed; //Adds the time elapsed since last loop to cooldown.
        if (wingsTimeElapsed < totalCooldownTime){ //If cooldown is still active.
            return; //Stops any code below from executing.
        }
        wingsTimeElapsed = 0; //Resets the cooldown timer.
        cooldown = false; //Turns off the cooldown
    }
	if (mainController.get_digital(DIGITAL_L1)){ //Looks for the press of L1 on the controller.
        if (wingsState == E_WINGTYPE_ENABLED){ //If wings are enabled.
            disableWings(); //Sets wings to disabled state.
        } else if (wingsState == E_WINGTYPE_DISABLED){ //If wings are disabled.
            enableWings(); //Sets wings to enabled state.
        }
        cooldown = true; //The button pressing is now in cooldown and needs to wait.
    }
}

void wings::initilize(){ //Initalizes the wings, ran in the initalization stage.
    wingsState = E_WINGTYPE_DISABLED; //Sets the wings to disabled.
    wingsTimeElapsed = 0; //Resets any cooldown timer.
    cooldown = false; //Turns off cooldown.
    disableWings(); //Retracts the wings.
}

wings masterWings; //Global wings object to be assessed from other files.