#include "main.h"
#define POTENTIOMETER_PORT 'A'

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();


	pros::lcd::register_btn1_cb(on_center_button);


	encoderOne.reset();
	encoderTwo.reset();
	encoderThree.reset();

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {



	 std::shared_ptr<OdomChassisController> chassis = ChassisControllerBuilder()
     .withMotors(
         1,  // Top left
         -7, // Top right (reversed)
         -14, // Bottom right (reversed)
         15   // Bottom left
     )

     .withGains(

			 {0.0005, 0, 00.00001}, // Distance controller gains 0.00005 works well but it stops and tilts bot
			 {0.0005, 0, 0.0000020},// 000006 works well // Turn controller gains  {0.001, 0, 0.0000020}
			 {0.0001, 0, 00.00001}  // Angle controller gains (helps drive straight)
			 /*

this works mostly

			 {0.001, 0, 0.0001}, // Distance controller gains
			 {0.001, 0, 00.00007},// 000006 works well // Turn controller gains 0.002 0 0.0001
			 {0.001, 0, 00.00001}


			 			// {0.001, 0, 0.0001}, // Distance controller gains
			 			// {0.0008, 0, 0.00005}, // Turn controller gains
			 			// {0.001, 0, 0.0001}  // Angle controller gains (helps drive straight)

         {0.001,0, 0.0001}, // Distance controller gains
         {0.0008, 0.00001, 0.00005}, // Turn controller gains
         {0.001, 0, 0.0001}  // Angle controller gains (helps drive straight)
*/
/* best so far
				 {0.001, 0, 0.0001}, // Distance controller gains
         {0.0008, 0, 0.00005}, // Turn controller gains
         {0.001, 0, 0.0001}  // Angle controller gains (helps drive straight)
    */
		 )
     .withSensors(
         ADIEncoder{'E', 'F'}, // left encoder
         ADIEncoder{'C', 'D', true},  // right encoder (reversed)
         ADIEncoder{'A', 'B'}  // middle encoder
     )

     // Green gearset
     // specify the tracking wheels diameter (2.75 in), track (7 in), and TPR (360)
     // specify the middle encoder distance (1 in) and diameter (2.75 in)
     .withDimensions(AbstractMotor::gearset::green, {{2.75_in, 14.0_in, 2.15_in, 2.75_in}, quadEncoderTPR})
     .withOdometry(StateMode::FRAME_TRANSFORMATION, 2_mm, 1_deg)
		 .withClosedLoopControllerTimeUtil(5,
		 5,
	25_ms)


     .buildOdometry();




		 const double liftkP = 0.001;
		 const double liftkI = 0.0001;
		 const double liftkD = 0.0001;


		 std::shared_ptr<AsyncPositionController<double, double>> asIntakeRight =
  AsyncPosControllerBuilder()
    .withMotor(19) // lift motor port 3
    .withGains({liftkP, liftkI, liftkD})
    .build();

		std::shared_ptr<AsyncPositionController<double, double>> asIntakeLeft =
 AsyncPosControllerBuilder()
	 .withMotor(16) // lift motor port 3
	 .withGains({liftkP, liftkI, liftkD})
	 .build();

		std::shared_ptr<AsyncPositionController<double, double>> flywheel =
 AsyncPosControllerBuilder()
	 .withMotor(3) // lift motor port 3
	 .withGains({liftkP, liftkI, liftkD})
	 .build();

	 std::shared_ptr<AsyncPositionController<double, double>> indexer =
AsyncPosControllerBuilder()
	.withMotor(17) // lift motor port 3
	.withGains({liftkP, liftkI, liftkD})
	.build();


	std::shared_ptr<XDriveModel> model = std::static_pointer_cast<XDriveModel>(
	 		std::static_pointer_cast<DefaultOdomChassisController>(chassis)->getModel()
	 	);


	chassis->setState({2_ft, 10_ft, 0_deg});
	chassis -> turnToPoint({2_ft, 11_ft});

	flywheel -> setTarget(1500);
	blooper = 127;
	asIntakeRight -> setTarget(225);
	asIntakeLeft -> setTarget(225);


}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {

	while (true) {

		//driver controls
		setDriveMotors();
		setIntakeMotors();
		setIndexerMotor();
		//intakeWidener();

		encoderPositions();

		pros::delay(10);
	}
}
