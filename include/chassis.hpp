#pragma once

#include "lemlib/chassis/chassis.hpp"

/////////////////////////////////////////
// EXTERN VARIABLES
/////////////////////////

extern lemlib::Chassis chassis;

///////////////////////////////////////
// SETTINGS
/////////////////////////

constexpr double VERTICAL_TRACKING_WHEEL_DIAMETER = 2.75; // vertical tracking wheel diameter in inches
constexpr double HORIZONTAL_TRACKING_WHEEL_DIAMETER = 2.75; // horizontal tracking wheel diameter in inches
constexpr double VERTICAL_TRACKING_WHEEL_OFFSET = -5.75; // vertical tracking wheel offset in inches
constexpr double HORIZONTAL_TRACKING_WHEEL_OFFSET = -2.5; // horizontal tracking wheel offset in inches

constexpr double DRIVETRAIN_TRACK_WIDTH = 10.0; // track width in inches
constexpr double DRIVETRAIN_WHEEL_DIAMETER = 4.0; // wheel diameter in inches
constexpr double DRIVETRAIN_RPM = 343.0; // drivetrain rpm
constexpr double DRIVETRAIN_HORIZONTAL_DRIFT = 2.0; // horizontal drift

constexpr double LINEAR_KP = 10.0; // linear proportional gain
constexpr double LINEAR_KI = 0.0; // linear integral gain
constexpr double LINEAR_KD = 3.0; // linear derivative gain
constexpr double LINEAR_ANTI_WINDUP = 3.0; // linear anti-windup
constexpr double LINEAR_SMALL_ERROR = 1.0; // linear small error range in inches
constexpr double LINEAR_LARGE_ERROR = 3.0; // linear large error range in inches
constexpr int LINEAR_SMALL_ERROR_TIMEOUT = 100; // linear small error range timeout in milliseconds
constexpr int LINEAR_LARGE_ERROR_TIMEOUT = 500; // linear large error range timeout in milliseconds
constexpr double LINEAR_MAX_ACCEL = 20.0; // linear maximum acceleration

constexpr double ANGULAR_KP = 2.0; // angular proportional gain
constexpr double ANGULAR_KI = 0.0; // angular integral gain
constexpr double ANGULAR_KD = 10.0; // angular derivative gain
constexpr double ANGULAR_ANTI_WINDUP = 3.0; // angular anti-windup
constexpr double ANGULAR_SMALL_ERROR = 1.0; // angular small error range in degrees
constexpr double ANGULAR_LARGE_ERROR = 3.0; // angular large error range in degrees
constexpr int ANGULAR_SMALL_ERROR_TIMEOUT = 100; // angular small error range timeout in milliseconds
constexpr int ANGULAR_LARGE_ERROR_TIMEOUT = 500; // angular large error range timeout in milliseconds
constexpr double ANGULAR_MAX_ACCEL = 0.0; // angular maximum acceleration
