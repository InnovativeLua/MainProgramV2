#include "catapult.hpp"


void catapult::opControl(){

}

catapult::catapult(int cataport){
    pros::Motor catapultMotor(cataport, pros::E_MOTOR_GEAR_100, false); //Initalizing the catapult motor object and sets to a red gear cartridge.
}