#pragma once

#include "lemlib/chassis/chassis.hpp"

// tracking wheels
extern lemlib::TrackingWheel verticalTrackingWheel;
extern lemlib::TrackingWheel horizontalTrackingWheel;

// drivetrain settings
extern lemlib::Drivetrain drivetrain;

// sensors for odometry
extern lemlib::OdomSensors sensors;

// lateral motion controller
extern lemlib::ControllerSettings linearController;

// angular motion controller
extern lemlib::ControllerSettings angularController;

// chassis
extern lemlib::Chassis chassis;