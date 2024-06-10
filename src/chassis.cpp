#include "chassis.hpp"
#include "devices.hpp"
#include "opcontrol.hpp"

// tracking wheels
lemlib::TrackingWheel verticalTrackingWheel(&verticalTrackingWheelEncoder, VERTICAL_TRACKING_WHEEL_DIAMETER,
                                            VERTICAL_TRACKING_WHEEL_OFFSET);
lemlib::TrackingWheel horizontalTrackingWheel(&horizontalTrackingWheelEncoder, HORIZONTAL_TRACKING_WHEEL_DIAMETER,
                                              HORIZONTAL_TRACKING_WHEEL_OFFSET);

// drivetrain settings
lemlib::Drivetrain drivetrain(&leftDrive, &rightDrive, DRIVETRAIN_TRACK_WIDTH, DRIVETRAIN_WHEEL_DIAMETER,
                              DRIVETRAIN_RPM, DRIVETRAIN_HORIZONTAL_DRIFT);

// sensors for odometry
lemlib::OdomSensors sensors(&verticalTrackingWheel, // vertical tracking wheel
                            nullptr, // vertical tracking wheel 2, set to nullptr as we don't have a second one
                            &horizontalTrackingWheel, // horizontal tracking wheel
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);

// lateral motion controller
lemlib::ControllerSettings linearController(LINEAR_KP, // proportional gain (kP)
                                            LINEAR_KI, // integral gain (kI)
                                            LINEAR_KD, // derivative gain (kD)
                                            LINEAR_ANTI_WINDUP, // anti windup
                                            LINEAR_SMALL_ERROR, // small error range, in inches
                                            LINEAR_SMALL_ERROR_TIMEOUT, // small error range timeout, in milliseconds
                                            LINEAR_LARGE_ERROR, // large error range, in inches
                                            LINEAR_LARGE_ERROR_TIMEOUT, // large error range timeout, in milliseconds
                                            LINEAR_MAX_ACCEL // maximum acceleration (slew)
);

// angular motion controller
lemlib::ControllerSettings angularController(ANGULAR_KP, // proportional gain (kP)
                                             ANGULAR_KI, // integral gain (kI)
                                             ANGULAR_KD, // derivative gain (kD)
                                             ANGULAR_ANTI_WINDUP, // anti windup
                                             ANGULAR_SMALL_ERROR, // small error range, in degrees
                                             ANGULAR_SMALL_ERROR_TIMEOUT, // small error range timeout, in milliseconds
                                             ANGULAR_LARGE_ERROR, // large error range, in degrees
                                             ANGULAR_LARGE_ERROR_TIMEOUT, // large error range timeout, in milliseconds
                                             ANGULAR_MAX_ACCEL // maximum acceleration (slew)
);

// create the chassis
lemlib::Chassis chassis(drivetrain, linearController, angularController, sensors, &throttleCurve, &steerCurve);