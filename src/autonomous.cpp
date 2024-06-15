#include "main.h"
#include "devices.hpp"
#include "chassis.hpp"

/**
 * tune the linear PID controller
 *
 */
void tuneLinearController() {
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, 20, 10000);
}

/**
 * tune the angular PID controller
 *
 */
void tuneAngularController() {
    chassis.setPose(0, 0, 0);
    chassis.turnToHeading(90, 10000);
}

/**
 * Runs during auto
 */
void autonomous() {
    // move the tracking wheels down
    trackingWheelLift.set_value(false);
    // tune linear controller
    // tuneLinearController();
    // tune angular controller
    // tuneAngularController();
}
