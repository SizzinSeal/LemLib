#include "main.h"
#include "devices.hpp"
#include "chassis.hpp"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 */
void initialize() {
    // set intake brake mode
    intake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors
    // start a task to print the robot location to the brain screen
    pros::Task screenTask([&]() {
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
            // delay to save resources
            pros::delay(16);
        }
    });
}

/**
 * Runs while the robot is disabled
 */
void disabled() {}

/**
 * runs after initialize if the robot is connected to field control
 */
void competition_initialize() {}

/**
 * Runs during auto
 */
void autonomous() {
    // move the tracking wheels down
    trackingWheelLift.set_value(false);
}
