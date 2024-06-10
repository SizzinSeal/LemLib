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

/**
 * Runs in driver control
 */
void opcontrol() {
    // lift the tracking wheels
    trackingWheelLift.set_value(true);
    bool hangToggle = false; // hang mechanism toggle
    // loop while in driver control
    while (true) {
        // hang mechanism
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) hangToggle = !hangToggle;
        hang.set_value(hangToggle);
        // wings
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) leftWing.set_value(true);
        else leftWing.set_value(false);
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) rightWing.set_value(true);
        else rightWing.set_value(false);
        // intake
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) intake.move(127);
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
            if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT) ||
                controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y))
                intake.move(-127);
            else intake.move(-50);
        } else intake.move(0);
        // drivetrain
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        chassis.arcade(leftY, rightX, 0, 0.75);
        // delay to save resources
        pros::delay(10);
    }
}
