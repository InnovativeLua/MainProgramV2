#pragma once
#include <vector>
#include "main.h"

class chassis {
 public:

    enum E_driveControl {
        E_ARCADE_CONTROL,
        E_TANK_CONTROL
    };

    chassis();


    std::vector<pros::Motor> left_motors;
    std::vector<pros::Motor> right_motors;

    pros::IMU ChassisIMU;


    pros::ADIEncoder left_tracker;
    pros::ADIEncoder right_tracker;

    bool driverControlPeriod;

    E_driveControl driveControl;

    void setDriveControl(int v);

    void updateDrive(int leftPower, int rightPower);

    void opControl();

    void updateLeft(int power);

    void updateRight(int power);

    void initialize(std::vector<std::vector<int>> leftMotorPorts, std::vector<std::vector<int>> rightMotorPorts);

    void turnToAngle(double targetAngle);

    //Runs constantly during auton
    void chassisAutoTask();
};