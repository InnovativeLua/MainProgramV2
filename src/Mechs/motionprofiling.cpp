#include "custom/mechs/motionprofiling.hpp"
#include "main.h"

void currentProfile::profileTask(){
    while (true){
        if (!profileActive){
            pros::delay(100);
            continue;
        }
        pros::delay(100);
    }
}