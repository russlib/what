
#include "main.h"
//drive motorss
pros::Motor frontLeft(4,pros::E_MOTOR_GEARSET_18,false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor frontRight(13,pros::E_MOTOR_GEARSET_18,false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor backLeft(15,pros::E_MOTOR_GEARSET_18,false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor backRight(14,pros::E_MOTOR_GEARSET_18,false, pros::E_MOTOR_ENCODER_COUNTS);
//intake motors
pros::Motor intakeRight(19,pros::E_MOTOR_GEARSET_18,false,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor intakeLeft(16, pros::E_MOTOR_GEARSET_18,false,pros::E_MOTOR_ENCODER_COUNTS);
//the part right after the ball intakes
pros::Motor indexer(18, pros::E_MOTOR_GEARSET_18,false,pros::E_MOTOR_ENCODER_COUNTS);
//the part the bloops the ball out into the top of the goal
pros::Motor blooper(1, pros::E_MOTOR_GEARSET_18,false,pros::E_MOTOR_ENCODER_COUNTS);
//CONTROLLER
pros::Controller controller(pros::E_CONTROLLER_MASTER);


//encoders and encoderStuffs
