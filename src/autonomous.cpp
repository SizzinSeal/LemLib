#include "main.h"
#include "devices.hpp"

/**
 * Runs during auto
 */
void autonomous() {
    // move the tracking wheels down
    trackingWheelLift.set_value(false);
}
