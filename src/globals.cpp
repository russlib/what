#include "main.h"

// Drive motors
pros::Motor frontLeft(1, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor frontRight(7, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor backLeft(15, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor backRight(14, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);

// Intake motors
pros::Motor intakeRight(10, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor intakeLeft(13, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);

// The part right after the ball intakes
pros::Motor indexer(3, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
// The part the bloops the ball out into the top of the goal
pros::Motor blooper(4, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);

// Controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Encoders and encoderStuffs
pros::ADIEncoder encoderOne('C', 'D', false);
pros::ADIEncoder encoderTwo('A', 'B', false);
pros::ADIEncoder encoderThree('E', 'F', false);

pros::ADIAnalogIn leftPotent('H');
pros::ADIAnalogIn rightPotent('G');
pros::ADIDigitalIn limitOne({{9,'A'}});

pros::ADIAnalogIn lineSensOne ({{9,'B'}});
pros::ADIAnalogIn lineSensTwo ({{9,'C'}});
pros::ADIAnalogIn lineSensThree ({{9,'D'}});
