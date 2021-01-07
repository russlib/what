#include "main.h"


//helper functions

void setIntake(int power) {
	intakeLeft = -power;
	intakeRight = power;
}

//the lower mech that picks up the balls after the intakes
void setIndexer(int iPower, int iSpeed) {
	indexer = -iPower;
	blooper = -iSpeed;
}


//driver control functions

void setIntakeMotors() {
	int power = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2));
	setIntake(power);
}

void setIndexerMotor() {
	int indexPower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) + controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2));
	int blooperPower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) + controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2));

	if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
		setIndexer(-indexPower, blooperPower);
	} else {
		setIndexer(indexPower, blooperPower);
	}
}

/*
// the higher up mechanism is called blooper
void blooper() {
	
}
void setblooperMotors() {
	
}
*/
