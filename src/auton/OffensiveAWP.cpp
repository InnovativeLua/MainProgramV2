#include "custom/auton/autons.hpp"

void OffensiveAWP(){
    masterChassis.updateLeft(-100);
    masterChassis.updateRight(100);
    
    pros::delay(1000);

    masterChassis.updateDrive(0, 0);
}