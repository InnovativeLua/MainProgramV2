#include "main.h"
#include "custom/mechs/catapult.hpp"
#include "custom/mechs/chassis.hpp"
#include "custom/mechs/intake.hpp" 
#include "custom/mechs/wings.hpp"
#include "custom/brain/ports.hpp"
#include "custom/brain/autonselector.hpp"
#include "custom/auton/autons.hpp"
#include <vector>

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */

AutonSelector masterAutonSelector = AutonSelector();


//MasterAutonSelector.addAutons()

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}



/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	masterWings.initilize();

	std::vector<Auton> autonsList = {};

	Auton a_DefensiveAWP;
	a_DefensiveAWP.autonFunction = *DefensiveAWP;
	a_DefensiveAWP.Name = "DefensiveAWP";

	Auton a_OffensiveAWP;
	a_OffensiveAWP.autonFunction = *OffensiveAWP;
	a_OffensiveAWP.Name = "OffensiveAWP";

	autonsList.push_back(a_DefensiveAWP);
	autonsList.push_back(a_OffensiveAWP);

	masterAutonSelector.addAutons(autonsList);

	pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	masterAutonSelector.callSelectedAuton();
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	const int mSecWaitTime = 10;

	while (true) {
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
		
		masterChassis.opControl();
		masterIntake.opControl();
		masterWings.opControl(mSecWaitTime);
		masterCata.opControl();

		pros::delay(mSecWaitTime);
	}
}