#include "opcontrol.hpp"
#include "devices.hpp"

// input curve for throttle input during driver control
lemlib::ExpoDriveCurve throttleCurve(THROTTLE_UPPER_DEADBAND, THROTTLE_LOWER_DEADBAND, THROTTLE_MIN_OUTPUT,
                                     THROTTLE_EXPO_GAIN);

// input curve for steer input during driver control
lemlib::ExpoDriveCurve steerCurve(STEER_UPPER_DEADBAND, STEER_LOWER_DEADBAND, STEER_MIN_OUTPUT, STEER_EXPO_GAIN);

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
        if (controller.get_digital_new_press(HANG_TOGGLE_BUTTON)) hangToggle = !hangToggle;
        hang.set_value(hangToggle);
        // wings
        if (controller.get_digital(LEFT_WING_BUTTON)) leftWing.set_value(true);
        else leftWing.set_value(false);
        if (controller.get_digital(RIGHT_WING_BUTTON)) rightWing.set_value(true);
        else rightWing.set_value(false);
        // intake
        if (controller.get_digital(INTAKE_IN_BUTTON)) intake.move(127);
        else if (controller.get_digital(INTAKE_OUT_BUTTON)) {
            if (controller.get_digital(LEFT_WING_BUTTON) || controller.get_digital(RIGHT_WING_BUTTON))
                intake.move(-OUTTAKE_FAST_SPEED);
            else intake.move(-OUTTAKE_SLOW_SPEED);
        } else intake.move(0);
        // drivetrain
        int leftY = controller.get_analog(THROTTLE_JOYSTICK);
        int rightX = controller.get_analog(STEER_JOYSTICK);
        chassis.arcade(leftY, rightX, 0, DESATURATE_BIAS);
        // delay to save resources
        pros::delay(10);
    }
}
