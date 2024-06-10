#include "devices.hpp"

// controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// pistons
pros::adi::DigitalOut leftWing(LEFT_WING_PORT);
pros::adi::DigitalOut rightWing(RIGHT_WING_PORT);
pros::adi::DigitalOut trackingWheelLift(TRACKING_WHEEL_LIFT_PORT);
pros::adi::DigitalOut hang(HANG_PORT);

// motors
pros::MotorGroup leftDrive(LEFT_DRIVE_PORTS, DRIVETRAIN_GEARSET);
pros::MotorGroup rightDrive(RIGHT_DRIVE_PORTS, DRIVETRAIN_GEARSET);
// the robot will either have a the intake motors connected or the kicker motors connected, but not both
pros::MotorGroup intake(INTAKE_PORTS);
pros::MotorGroup kicker(KICKER_PORTS);

// sensors
pros::Rotation verticalTrackingWheelEncoder(VERTICAL_TRACKING_WHEEL_PORT);
pros::Rotation horizontalTrackingWheelEncoder(HORIZONTAL_TRACKING_WHEEL_PORT);
pros::IMU imu(IMU_PORT);