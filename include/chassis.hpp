#pragma once
#include <vector>
#include "main.h"

pros::Motor leftFrontMotor(21, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);

class chassis {

private:
    pros::Motor leftFrontMotor = pros::Motor(5, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
    pros::Motor leftBackMotor = pros::Motor(5, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
    pros::Motor leftTopMotor = pros::Motor(5, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);

    pros::Motor rightFrontMotor = pros::Motor(5, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
    pros::Motor rightBackMotor = pros::Motor(5, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
    pros::Motor rightTopMotor = pros::Motor(5, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);

 public:
    enum E_driveControl {
        E_ARCADE_CONTROL,
        E_TANK_CONTROL
    };

    chassis();

    std::vector<pros::Motor> ActiveLeftMotors = {leftFrontMotor, leftBackMotor, leftTopMotor};
    std::vector<pros::Motor> ActiveRightMotors = {rightFrontMotor, rightBackMotor, rightTopMotor};

    pros::IMU ChassisIMU = pros::IMU(1);

    pros::ADIEncoder left_tracker = pros::ADIEncoder('A', 'B');
    pros::ADIEncoder right_tracker = pros::ADIEncoder('B', 'C');

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