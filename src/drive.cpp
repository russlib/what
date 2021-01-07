#include "main.h"

//todo
// add header functions
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

	if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
		pros::lcd::set_text(1, encoderText);
	}

	if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
		pros::lcd::clear_line(1);
	}

	if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
		//if (encoderOne.get_value() < 1000)
		//double encoderStuffs = .get_value();

		//auto goof = std::to_string(encoderStuffs);
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
