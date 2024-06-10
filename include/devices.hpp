#pragma once

#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/misc.hpp"
#include "pros/motor_group.hpp"
#include "pros/rotation.hpp"

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