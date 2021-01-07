
#include "main.h"
#define QUAD_TOP_PORT 'C'
#define QUAD_BOTTOM_PORT 'D'

//todo
// add header fucntions
//yo commented
//helper fucntions
void driveXY(double yDirec,  double xDirec, double turningSpeed, double speed_scalar){
frontLeft = yDirec + xDirec + turningSpeed;
backLeft = yDirec - xDirec + turningSpeed;
frontRight = turningSpeed - yDirec + xDirec;
backRight = turningSpeed - yDirec - xDirec;
}
//driver control fucntions
void setDriveMotors()
{
double speedMulti = speedMulti * 1;
double driveY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
double driveX = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
double turningRate = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
driveXY(driveY, driveX, turningRate, speedMulti);
}


void encoderPositions(){


/*

  std::cout << "Motor Position: "<< backRight.get_position();

  double boof = backRight.get_position();
	auto goof = std::to_string(boof);


*/


//std::cout << "Motor Position: "<< encoder.get_position();
pros::ADIEncoder encoder (QUAD_TOP_PORT, QUAD_BOTTOM_PORT);
double boof = encoder.get_value();
auto goof = std::to_string(boof);
double loof = encoder.get_value();
auto foof = std::to_string(loof);
pros::lcd::set_text(1, foof);


if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)){

  pros::lcd::set_text(1, goof);}

  if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_B))
  {
  pros::lcd::clear_line(1);
  }
if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)){



//if( encoderOne.get_value() < 1000)
  //double encoderStuffs = .get_value();

  //auto goof = std::to_string(encoderStuffs);
  //  pros::lcd::set_text(2, goof);





}


}






/*
void showScreenValues(){
  if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)){

  }

  if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)){

  }


}
*/
