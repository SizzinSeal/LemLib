#pragma once

#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/misc.hpp"
#include "pros/motor_group.hpp"
#include "pros/rotation.hpp"

/////////////////////////////////////////
// EXTERN VARIABLES
/////////////////////////

// controller
extern pros::Controller controller;

// pistons
extern pros::adi::DigitalOut leftWing;
extern pros::adi::DigitalOut rightWing;
extern pros::adi::DigitalOut trackingWheelLift;
extern pros::adi::DigitalOut hang;

// motors
extern pros::MotorGroup leftDrive;
extern pros::MotorGroup rightDrive;
extern pros::MotorGroup intake;
extern pros::MotorGroup kicker;

// sensors
extern pros::Rotation verticalTrackingWheelEncoder;
extern pros::Rotation horizontalTrackingWheelEncoder;
extern pros::IMU imu;

///////////////////////////////////////
// PORTS
/////////////////////////

constexpr char LEFT_WING_PORT = 'h';
constexpr char RIGHT_WING_PORT = 'g';
constexpr char TRACKING_WHEEL_LIFT_PORT = 'a';
constexpr char HANG_PORT = 'b';

#define LEFT_DRIVE_PORTS                                                                                               \
    { -13, 12, -14 }
#define RIGHT_DRIVE_PORTS                                                                                              \
    { 18, -16, 17 }
#define DRIVETRAIN_GEARSET pros::MotorGearset::blue

#define INTAKE_PORTS                                                                                                   \
    { 15, -19 }
#define KICKER_PORTS                                                                                                   \
    { -2, 9 }

constexpr std::int8_t VERTICAL_TRACKING_WHEEL_PORT = -11;
constexpr std::int8_t HORIZONTAL_TRACKING_WHEEL_PORT = 20;
constexpr std::int8_t IMU_PORT = 10;
