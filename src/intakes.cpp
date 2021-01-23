#include "main.h"


//helper functions

void intakeWidener(){

//todo check to see what efficency valuse give
//changed to opening with potentiometer

    double thisWide = 700;
    double intakeTarget = thisWide;

    if((intakeTarget > rightPotent.get_value()) or (intakeTarget +300 < rightPotent.get_value())){
      int intakeWidePowerR = (intakeTarget - rightPotent.get_value());
	    setIntakeRight(intakeWidePowerR);
  }
      if((intakeTarget > leftPotent.get_value()) or (intakeTarget +300 < leftPotent.get_value())  ){
       int intakeWidePowerL = (intakeTarget - leftPotent.get_value());
       setIntakeLeft(intakeWidePowerL);
}

}

void setIntakeRight(int inPowerR) {

	intakeRight = inPowerR;
}

void setIntakeLeft(int inPowerL){

  	intakeLeft = -inPowerL;
}

//the lower mech that picks up the balls after the intakes
void setIndexer(int iPower) {
	indexer = -iPower;

}
void setBlooper(int blooperPower){
blooper = blooperPower;

}

void setIntakeMotors() {
  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
    intakeWidener();
  }
  else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
    int powerIntakes = 127;

    setIntakeLeft(-powerIntakes);
    setIntakeRight(-powerIntakes);
  }
  else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)){
    int powerIntakes = 127;

    setIntakeLeft(-powerIntakes);
    setIntakeRight(-powerIntakes);
  }
  else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
    int powerIntakes = 127;

    setIntakeLeft(-powerIntakes);
    setIntakeRight(-powerIntakes);
  } else {
    setIntakeLeft(0);
    setIntakeRight(0);
  }
}




void setIndexerMotor() {
  /*
 if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {

   int power = 127;
 	setIndexer(power);
}
*/

int powerElevator = 127;
if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
 setIndexer(-powerElevator);
 setBlooper(powerElevator);
}

else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
setIndexer(powerElevator);
setBlooper(powerElevator);

}
else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
  setIndexer(-powerElevator);
  setBlooper(-powerElevator);
}

else{
  setIndexer(0);
  setBlooper(0);
}



/*
int powerElevator = -127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) -  controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2));
setIndexer(powerElevator);

if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
  setBlooper(-powerElevator);
}
else{
setBlooper(powerElevator);
}
*/



}
/*
else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
  int powerReverse = -127;
  setIndexer(powerReverse);
  setBlooper(powerReverse);


}
*/






/*
double EfficencyRight = frontRight.get_efficiency();//may have cool inatake collapse for resetting bot
double EfficencyLeft = frontLeft.get_efficiency();
double averageEfficency = (EfficencyLeft + EfficencyRight)/2;
double smoothEffiency;

smoothEffiency = 10 * (smoothEffiency * 0.9 + averageEfficency * 0.1);


return smoothEffiency;
*/










/*
void setblooperMotors(int blooperP){
blooper = -blooperP;

}
*/








//driver control functions




  /*

  else{

if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
  int power = 127;
  setIntakeLeft(-power);
  setIntakeRight(-power);
  setIndexer(power,power);
}


}*/
  //int power = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) -  controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2));
	//setIntake(power);











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





/*
// the higher up mechanism is called blooper
void blooper() {

}
void setblooperMotors() {

}
*/
