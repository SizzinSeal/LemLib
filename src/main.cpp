#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "lemlib/chassis/trackingWheel.hpp"
#include "pros/adi.hpp"
#include "pros/misc.h"

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

// tracking wheels
lemlib::TrackingWheel verticalTrackingWheel(&verticalTrackingWheelEncoder, lemlib::Omniwheel::NEW_275, -5.75);
lemlib::TrackingWheel horizontalTrackingWheel(&horizontalTrackingWheelEncoder, lemlib::Omniwheel::NEW_275, -2.5);

// drivetrain settings
lemlib::Drivetrain drivetrain(&leftDrive, // left motor group
                              &rightDrive, // right motor group
                              10, // 10 inch track width
                              lemlib::Omniwheel::NEW_4, // using new 4" omnis
                              343, // drivetrain rpm is 360
                              2 // horizontal drift is 2. If we had traction wheels, it would have been 8
);

// sensors for odometry
lemlib::OdomSensors sensors(&verticalTrackingWheel, // vertical tracking wheel
                            nullptr, // vertical tracking wheel 2, set to nullptr as we don't have a second one
                            &horizontalTrackingWheel, // horizontal tracking wheel
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);

// lateral motion controller
lemlib::ControllerSettings linearController(10, // proportional gain (kP)
                                            0, // integral gain (kI)
                                            3, // derivative gain (kD)
                                            3, // anti windup
                                            1, // small error range, in inches
                                            100, // small error range timeout, in milliseconds
                                            3, // large error range, in inches
                                            500, // large error range timeout, in milliseconds
                                            20 // maximum acceleration (slew)
);

// angular motion controller
lemlib::ControllerSettings angularController(2, // proportional gain (kP)
                                             0, // integral gain (kI)
                                             10, // derivative gain (kD)
                                             3, // anti windup
                                             1, // small error range, in degrees
                                             100, // small error range timeout, in milliseconds
                                             3, // large error range, in degrees
                                             500, // large error range timeout, in milliseconds
                                             0 // maximum acceleration (slew)
);

// input curve for throttle input during driver control
lemlib::ExpoDriveCurve throttleCurve(0, // upper joystick deadband out of 127
                                     0, // lower joystick deadband out of 127
                                     12, // minimum output where drivetrain will move out of 127
                                     1.019 // expo curve gain
);

// input curve for steer input during driver control
lemlib::ExpoDriveCurve steerCurve(0, // upper joystick deadband out of 127
                                  0, // lower joystick deadband out of 127
                                  15, // minimum output where drivetrain will move out of 127
                                  1.019 // expo curve gain
);

// create the chassis
lemlib::Chassis chassis(drivetrain, linearController, angularController, sensors, &throttleCurve, &steerCurve);

/**
 * Runs initialization code. This occurs as soon as the program is started.
 */
void initialize() {
    // set intake brake mode
    intake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors
    // start a task to print the robot location to the brain screen
    pros::Task screenTask([&]() {
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
            // delay to save resources
            pros::delay(16);
        }
    });
}

/**
 * Runs while the robot is disabled
 */
void disabled() {}

/**
 * runs after initialize if the robot is connected to field control
 */
void competition_initialize() {}

/**
 * Runs during auto
 */
void autonomous() {
    // move the tracking wheels down
    trackingWheelLift.set_value(false);
}

/**
 * Runs in driver control
 */
void opcontrol() {
    // lift the tracking wheels
    trackingWheelLift.set_value(true);
    bool hangToggle = false; // hang mechanism toggle
    // loop while in driver control
    while (true) {
        // hang mechanism
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) hangToggle = !hangToggle;
        hang.set_value(hangToggle);
        // wings
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) leftWing.set_value(true);
        else leftWing.set_value(false);
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) rightWing.set_value(true);
        else rightWing.set_value(false);
        // intake
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) intake.move(127);
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
            if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT) ||
                controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y))
                intake.move(-127);
            else intake.move(-50);
        } else intake.move(0);
        // drivetrain
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        chassis.arcade(leftY, rightX, 0, 0.75);
        // delay to save resources
        pros::delay(10);
    }
}
