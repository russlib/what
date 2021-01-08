#include "main.h"

//todo
// add header functions
//switch encoder 2 and three
//check what pros is wanting and do it based on that
//yo commented


//helper functions

void driveXY(double yDirec, double xDirec, double turningSpeed) {
	frontLeft = yDirec + xDirec + turningSpeed;
	backLeft = yDirec - xDirec + turningSpeed;
	frontRight = turningSpeed - yDirec + xDirec;
	backRight = turningSpeed - yDirec - xDirec;
}


//driver control functions

void setDriveMotors() {
	double driveY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
	double driveX = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
	double turningRate = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
	driveXY(driveY, driveX, turningRate);
}


void encoderPositions() {

	//std::cout << "Motor Position: " << backRight.get_position() << std::endl;

	std::cout << "Encoder Position: " << encoderOne.get_value() << std::endl;

	std::string encoderText = std::to_string(encoderOne.get_value());
	pros::lcd::set_text(0, encoderText);
//encoder two is in reality encoder 3
	std::string encoderTextThree = std::to_string(encoderThree.get_value());
	pros::lcd::set_text(1, encoderTextThree);

	std::string motorText = std::to_string(frontLeft.get_position());
	pros::lcd::set_text(2, motorText);

	std::string motorEfficency = std::to_string(frontLeft.get_efficiency());
  // pros::lcd::set_text(3, motorEfficency);

	if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
		pros::lcd::set_text(1, encoderText);
		pros::lcd::set_text(2,motorText);
	}

	if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
		pros::lcd::clear_line(1);
		pros::lcd::clear_line(2);
		pros::lcd::clear_line(3);
	}

	if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
		//if (encoderOne.get_value() < 1000)
		//double encoderStuffs = .get_value();

		//pros::lcd::set_text(2, goof);
	}
}

/*
void showScreenValues() {
	if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {

	}

	if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {

	}
}
*/
