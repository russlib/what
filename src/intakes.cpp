
//helper funcitons
#include "main.h"
void setIntake(int power){
  intakeLeft = -power;
  intakeRight = power;
}

/*
void setIntake(int power){
  intakeLeft = power;
  intakeRight = power;
}
*/
//driver controller functions




void setIntakeMotors() {
  int Power = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2));
setIntake(Power);
}


//the lower mech that picks up the balls after the intakes
void setIndexer(int iPower,int iSpeed) {
indexer = -iPower;

blooper =  -iSpeed;

}



void setIndexerMotor(){
  int indexPower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) + controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) );
int blooperPower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) + controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) );

if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)>0){
  setIndexer(-indexPower,blooperPower);
}
if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == 0){
  setIndexer(indexPower,blooperPower);
}

}
/*
//the higher up mechanism is called blooper
void blooper(){
}
void setblooperMotors(){
}
*/
