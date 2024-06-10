#include "devices.hpp"

// controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// pistons
pros::adi::DigitalOut leftWing('h');
pros::adi::DigitalOut rightWing('g');
pros::adi::DigitalOut trackingWheelLift('a');
pros::adi::DigitalOut hang('b');

// motors
pros::MotorGroup leftDrive({-13, 12, -14}, pros::MotorGearset::blue);
pros::MotorGroup rightDrive({18, -16, 17}, pros::MotorGearset::blue);
// the robot will either have a the intake motors connected or the kicker motors connected, but not both
pros::MotorGroup intake({15, -19});
pros::MotorGroup kicker({-2, 9});

// sensors
pros::Rotation verticalTrackingWheelEncoder(-11);
pros::Rotation horizontalTrackingWheelEncoder(20);
pros::IMU imu(10);