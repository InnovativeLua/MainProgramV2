#pragma once
#include <vector>
#include "main.h"
#include "custom/brain/ports.hpp"

class chassis {

 public:

    pros::Motor leftFrontMotor = pros::Motor(3, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
    pros::Motor leftBackMotor = pros::Motor(1, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);
    pros::Motor leftTopMotor = pros::Motor(2, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);

    pros::Motor rightFrontMotor = pros::Motor(6, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
    pros::Motor rightBackMotor = pros::Motor(5, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);
    pros::Motor rightTopMotor = pros::Motor(4, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);

    enum E_driveControl {
        E_ARCADE_CONTROL,
        E_TANK_CONTROL
    };

    std::vector<pros::Motor> ActiveLeftMotors = {leftFrontMotor, leftBackMotor, leftTopMotor};
    std::vector<pros::Motor> ActiveRightMotors = {rightFrontMotor, rightBackMotor, rightTopMotor};

    pros::IMU ChassisIMU = pros::IMU(1);

    pros::ADIEncoder left_tracker = pros::ADIEncoder('C', 'D');
    pros::ADIEncoder right_tracker = pros::ADIEncoder('E', 'F');

    bool driverControlPeriod;

    E_driveControl driveControl;

    void setDriveControl(int v);

    void updateDrive(int leftPower, int rightPower);

    void opControl();

    void updateLeft(int power);

    void updateRight(int power);

    void turnToAngle(double targetAngle);

    //Runs constantly during auton
    void chassisAutoTask();

    void initialize();
};

extern chassis masterChassis;