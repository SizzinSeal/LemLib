#include "main.h"
#include "devices.hpp"
#include "chassis.hpp"

void tuneLinearController() {
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, 20, 10000);
}

/**
 * Runs during auto
 */
void autonomous() {
    // move the tracking wheels down
    trackingWheelLift.set_value(false);
    // tune linear controller
    tuneLinearController();
}
