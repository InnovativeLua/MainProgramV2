#include "custom/mechs/wings.hpp"
#include "custom/brain/controller.hpp"

void wings::enableWings(){
    wingsPiston1.set_value(true);
    wingsPiston2.set_value(true);
    wingsState = E_WINGTYPE_ENABLED;
}

void wings::disableWings(){
    wingsPiston1.set_value(false);
    wingsPiston2.set_value(false);
    wingsState = E_WINGTYPE_DISABLED;
}


void wings::opControl(int driveTimeElapsed){
    if (cooldown){
        wingsTimeElapsed += driveTimeElapsed;
        if (wingsTimeElapsed < totalCooldownTime){
            return;
        }
        wingsTimeElapsed = 0;
        cooldown = false;
    }
	if (mainController.get_digital(DIGITAL_L1)){
        if (wingsState == E_WINGTYPE_ENABLED){
            disableWings();

        } else if (wingsState == E_WINGTYPE_DISABLED){
            enableWings();
        }
        cooldown = true;
    }
}

void wings::initilize(){
    wingsState = E_WINGTYPE_DISABLED;
    wingsTimeElapsed = 0;
    cooldown = false;
    disableWings();
}