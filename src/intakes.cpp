#include "main.h"


//helper functions

int intakeWidener(){

//todo check to see what efficency valuse give
//changed to opening with potentiometer

    double thisWide = 1000;
    double intakeTarget = thisWide;

    if((intakeTarget > rightPotent.get_value()) or (intakeTarget +300 < rightPotent.get_value())){
      int intakeWidePowerR = (intakeTarget - rightPotent.get_value());
	    setIntakeRight(intakeWidePowerR);
  }



     if((intakeTarget > leftPotent.get_value()) or (intakeTarget +300 < leftPotent.get_value())  ){
       int intakeWidePowerL = (intakeTarget - leftPotent.get_value());
       setIntakeLeft(intakeWidePowerL);
}






/*
double EfficencyRight = frontRight.get_efficiency();//may have cool inatake collapse for resetting bot
double EfficencyLeft = frontLeft.get_efficiency();
double averageEfficency = (EfficencyLeft + EfficencyRight)/2;
double smoothEffiency;

smoothEffiency = 10 * (smoothEffiency * 0.9 + averageEfficency * 0.1);


return smoothEffiency;
*/
}







void setIntakeRight(int inPowerR) {

	intakeRight = inPowerR;
}

void setIntakeLeft(int inPowerL){

  	intakeLeft = -inPowerL;
}

//the lower mech that picks up the balls after the intakes
void setIndexer(int iPower, int iSpeed) {
	indexer = iPower;
	blooper = -iPower;
}




//driver control functions



void setIntakeMotors() {


  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
  {
    intakeWidener();
  }

else{
  int power = 127 * controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2);
	setIntakeLeft(-power);
  setIntakeRight(-power);
     }
  //int power = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) -  controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2));
	//setIntake(power);
                         }

void setIndexerMotor() {




  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {

    int blooperPower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1));

intakeWidener();
  }



/*
	int indexPower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) + controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2));
	int blooperPower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) + controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2));

	if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
		setIndexer(indexPower, blooperPower);
	}

  else {
		setIndexer(-indexPower, blooperPower);
	}


*/
}




/*
// the higher up mechanism is called blooper
void blooper() {

}
void setblooperMotors() {

}
*/
