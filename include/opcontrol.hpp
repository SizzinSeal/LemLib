#pragma once

#include "chassis.hpp"

/////////////////////////////////////////
// EXTERN VARIABLES
/////////////////////////

// input curve for throttle input during driver control
extern lemlib::ExpoDriveCurve throttleCurve;

// input curve for steer input during driver control
extern lemlib::ExpoDriveCurve steerCurve;

///////////////////////////////////////
// SETTINGS
/////////////////////////

constexpr int THROTTLE_UPPER_DEADBAND = 0; // upper joystick deadband out of 127
constexpr int THROTTLE_LOWER_DEADBAND = 0; // lower joystick deadband out of 127
constexpr int THROTTLE_MIN_OUTPUT = 12; // minimum output where drivetrain will move out of 127
constexpr double THROTTLE_EXPO_GAIN = 1.019; // expo curve gain

constexpr int STEER_UPPER_DEADBAND = 0; // upper joystick deadband out of 127
constexpr int STEER_LOWER_DEADBAND = 0; // lower joystick deadband out of 127
constexpr int STEER_MIN_OUTPUT = 15; // minimum output where drivetrain will move out of 127
constexpr double STEER_EXPO_GAIN = 1.019; // expo curve gain

constexpr double DESATURATE_BIAS = 0.75; // bias for desaturation. 0 prioritizes throttle, 1 prioritizes steering

constexpr int INTAKE_IN_SPEED = 127; // speed for intaking
constexpr int OUTTAKE_FAST_SPEED = 127; // speed for outtaking with wings
constexpr int OUTTAKE_SLOW_SPEED = 50; // speed for outtaking without wings

///////////////////////////////////////
// CONTROLS
/////////////////////////

#define HANG_TOGGLE_BUTTON pros::E_CONTROLLER_DIGITAL_UP // button to toggle the hang mechanism
#define LEFT_WING_BUTTON pros::E_CONTROLLER_DIGITAL_RIGHT // button to activate the left wing
#define RIGHT_WING_BUTTON pros::E_CONTROLLER_DIGITAL_Y // button to activate the right wing
#define INTAKE_IN_BUTTON pros::E_CONTROLLER_DIGITAL_L1 // button to intake
#define INTAKE_OUT_BUTTON pros::E_CONTROLLER_DIGITAL_L2 // button to outtake
#define THROTTLE_JOYSTICK pros::E_CONTROLLER_ANALOG_LEFT_Y // joystick for throttle
#define STEER_JOYSTICK pros::E_CONTROLLER_ANALOG_RIGHT_X // joystick for steering
