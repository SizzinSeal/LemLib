#include "opcontrol.hpp"
#include "devices.hpp"

// input curve for throttle input during driver control
lemlib::ExpoDriveCurve throttleCurve(0, // upper joystick deadband out of 127
                                     0, // lower joystick deadband out of 127
                                     12, // minimum output where drivetrain will move out of 127
                                     1.019 // expo curve gain
);

// input curve for steer input during driver control
lemlib::ExpoDriveCurve steerCurve(0, // upper joystick deadband out of 127
                                  0, // lower joystick deadband out of 127
                                  15, // minimum output where drivetrain will move out of 127
                                  1.019 // expo curve gain
);

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
