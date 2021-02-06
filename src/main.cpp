#include "main.h"




//todo list


// make functions to use sesnsors to do hard resets.
// line sensors reset
//wall sensors resets
// ultrasonic ball detection

// ball indexer


//better driver skills trackers




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
			{0.0009, 0, 00.00003}, // Distance controller gains 0.00005 works well but it stops and tilts bot
			{0.0009,0, 0.000015},// 000006 works well // Turn controller gains  {0.001, 0, 0.0000020}
			{0.0007, 0, 00.00001}  // Angle controller gains (helps drive straight)
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
		.withDimensions(AbstractMotor::gearset::green, {{2.787_in, 14.38_in, 2.11_in, 2.787_in}, quadEncoderTPR})
		.withOdometry(StateMode::FRAME_TRANSFORMATION, 2_mm, 1_deg)
		.withClosedLoopControllerTimeUtil(5, 5, 25_ms)
		.buildOdometry();






	std::shared_ptr<XDriveModel> model = std::static_pointer_cast<XDriveModel>(
		std::static_pointer_cast<DefaultOdomChassisController>(chassis)->getModel()
	);




	std::string startTest = chassis -> getState().str();
	pros::lcd::set_text(2, startTest);
// pros::delay(500);
// chassis -> setMaxVelocity(100);
// chassis->setState({0_ft, 0_ft, 0_deg});
// chassis -> driveToPoint({2_ft, 0_ft});
// chassis -> driveToPoint({2_ft, 2_ft});
// chassis -> driveToPoint({0_ft, 2_ft});
// chassis -> driveToPoint({0_ft, 0_ft});
// chassis -> turnToPoint({2_ft, 0_ft});

//speed and states
//chassis->setState({1.5_ft, 10.66_ft, 315_deg});
//chassis -> setMaxVelocity(600);

//drivetrain movement
// 	chassis->driveToPoint({6.9_ft, 9_ft});
// 	chassis->turnToPoint({6.5_ft, 6_ft});
// 	chassis ->turnAngle(2_deg);
// 	chassis->moveDistance(1_ft);
//model -> strafe(-20);

//delays
// 	pros::delay(700);

//moves intakes foward(?)
// 	intakeRight.move_relative(-5000, 600);
// 	intakeLeft.move_relative(5000, 600);

//moves blooper and indexer forwar(?)
// 	blooper.move_relative(500, 600);
// 	blooper = 127;
// 	indexer = -127;

//soft start/stops
// 	model -> forward(-50);
// 	pros::delay(180);
// 	model -> forward(-15);
// 	pros::delay(15);
// 	model -> forward(-50);
// 	pros::delay(50);
// 	model -> forward(-90);
// 	pros::delay(50);
// 	model -> forward(-100);
// 	pros::delay(250);








chassis->setState({1.616_ft, 10.717_ft, -31_deg});
chassis ->setMaxVelocity(200);
blooper.move_relative(1000, 600);
chassis -> turnToPoint({2.5_ft, 10_ft});
chassis -> driveToPoint({2.5_ft, 10_ft});
chassis ->setMaxVelocity(90);

chassis -> turnToPoint({6.5_ft, 8.2_ft});
chassis -> driveToPoint({6.5_ft, 8.2_ft});

chassis -> turnToPoint({6.4_ft, 6_ft});




	model -> forward(15);
	pros::delay(50);
	model -> forward(50);
	pros::delay(50);
	model -> forward(100);
	pros::delay(300);
	model -> forward(0);
	pros::delay(300);

	model -> forward(-15);
	pros::delay(50);
	model -> forward(-50);
	pros::delay(50);
	model -> forward(-100);
	pros::delay(340);
	model -> forward(0);
	pros::delay(300);

	model -> forward(15);
	pros::delay(50);
	model -> forward(50);
	pros::delay(50);
	model -> forward(100);
	pros::delay(300);
	model -> forward(0);
	pros::delay(300);

	model -> forward(-15);
	pros::delay(50);
	model -> forward(-50);
	pros::delay(30);
	model -> forward(-100);
	pros::delay(340);
	model -> forward(0);
	pros::delay(300);

	model -> forward(15);
	pros::delay(50);
	model -> forward(50);
	pros::delay(50);
	model -> forward(100);
	pros::delay(300);
	model -> forward(0);
	pros::delay(300);

	model -> forward(-15);
	pros::delay(50);
	model -> forward(-50);
	pros::delay(50);
	model -> forward(-100);
	pros::delay(340);
	model -> forward(0);
	pros::delay(300);

	model -> forward(15);
	pros::delay(50);
	model -> forward(50);
	pros::delay(50);
	model -> forward(100);
	pros::delay(300);
	model -> forward(0);
	pros::delay(300);

	model -> forward(-15);
	pros::delay(50);
	model -> forward(-50);
	pros::delay(50);
	model -> forward(-100);
	pros::delay(340);
	model -> forward(0);
	pros::delay(300);



















	// starts near goal
	// flips ball into goal
	// drives to 2.33_ft, 10_ft
	// open intakes
	// intake ball
	// turn to 6.375_ft, 8_ft
	// drive forward 1_ft
	// move back 4_in
	// open intakes
	// drive to 6_ft, 7_ft
	// score stored ball into goal
	// move back to 6_ft, 10_ft
	// drive to 8.75_ft, 2_ft
	// close intakes around ball
	// strafe left until wall
	// drive forward about 1_ft
	// open loop turn for a while
	// score stored ball






























while(true){
	std::cout << "Encoder Position: " << chassis -> getState().str() << std::endl;


	std::string secondEncoder = std::to_string(encoderTwo.get_value());
	std::cout << "tracking ticks: " << secondEncoder << std::endl;

	pros::lcd::set_text(1, secondEncoder);
	pros::delay(1000);
}



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

	std::shared_ptr<OdomChassisController> chassis = ChassisControllerBuilder()
		.withMotors(
			1,  // Top left
			-7, // Top right (reversed)
			-14, // Bottom right (reversed)
			15   // Bottom left
		)
		.withGains(
			{0.0009, 0, 00.00003}, // Distance controller gains 0.00005 works well but it stops and tilts bot
			{0.0009,0, 0.000015},// 000006 works well // Turn controller gains  {0.001, 0, 0.0000020}
			{0.0007, 0, 00.00001}  // Angle controller gains (helps drive straight)
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
		.withDimensions(AbstractMotor::gearset::green, {{2.787_in, 14.52_in, 2.15_in, 2.787_in}, quadEncoderTPR})
		.withOdometry(StateMode::FRAME_TRANSFORMATION, 2_mm, 1_deg)
		.withClosedLoopControllerTimeUtil(5, 5, 25_ms)
		.buildOdometry();

	while (true) {

		//driver controls
		setDriveMotors();
		setIntakeMotors();
		setIndexerMotor();
		//intakeWidener();

		encoderPositions();
std::cout << "Encoder Position: " << chassis -> getState().str() << std::endl;


		pros::delay(10);
	}
}


//speed and states
//chassis->setState({1.5_ft, 10.66_ft, 315_deg});
//chassis -> setMaxVelocity(600);

//drivetrain movement
// 	chassis->driveToPoint({6.9_ft, 9_ft});
// 	chassis->turnToPoint({6.5_ft, 6_ft});
// 	chassis ->turnAngle(2_deg);
// 	chassis->moveDistance(1_ft);
//model -> strafe(-20);

//delays
// 	pros::delay(700);

//moves intakes foward(?)
// 	intakeRight.move_relative(-5000, 600);
// 	intakeLeft.move_relative(5000, 600);

//moves blooper and indexer forwar(?)
// 	blooper.move_relative(500, 600);
// 	blooper = 127;
// 	indexer = -127;


//soft start/stops

// 	model -> forward(-50);
// 	pros::delay(180);
// 	model -> forward(-15);
// 	pros::delay(15);
// 	model -> forward(-50);
// 	pros::delay(50);
// 	model -> forward(-90);
// 	pros::delay(50);
// 	model -> forward(-100);
// 	pros::delay(250);






	//chassis->setState({1.5_ft, 10.66_ft, 315_deg});
// 	chassis->setState({2.0_ft, 10.66_ft, -31.2_deg});
//
// 	blooper.move_relative(500, 600);
// 	pros::delay(700);
//
// 	intakeRight.move_relative(-5000, 600);
// 	intakeLeft.move_relative(5000, 600);
// 	chassis -> setMaxVelocity(600);
//
//
// 	blooper = 127;
// 	indexer = -127;
// 	pros::delay(1600);
// 	blooper = 0;
// 	indexer = 0;
// 	chassis->driveToPoint({6.9_ft, 9_ft});
//
// 	chassis->turnToPoint({6.5_ft, 6_ft});
// 	chassis ->turnAngle(2_deg);
// 	chassis->moveDistance(1_ft);
//
//
// 	model -> forward(50);
// 	pros::delay(180);
// 	model -> forward(15);
// 	pros::delay(15);
// 	model -> forward(50);
// 	pros::delay(50);
// 	model -> forward(90);
// 	pros::delay(50);
// 	model -> forward(100);
// 	pros::delay(100);
// 	model -> forward(100);
// 	pros::delay(200);
//
//
// 	model -> forward(-50);
// 	pros::delay(180);
// 	model -> forward(-15);
// 	pros::delay(15);
// 	model -> forward(-50);
// 	pros::delay(50);
// 	model -> forward(-90);
// 	pros::delay(50);
// 	model -> forward(-100);
// 	pros::delay(250);
//
// 	model -> forward(50);
// 	pros::delay(180);
// 	model -> forward(15);
// 	pros::delay(15);
// 	model -> forward(50);
// 	pros::delay(50);
// 	model -> forward(90);
// 	pros::delay(50);
// 	model -> forward(100);
// 	pros::delay(100);
// 	model -> forward(100);
// 	pros::delay(200);
//
//
// 	model -> forward(-50);
// 	pros::delay(180);
// 	model -> forward(-15);
// 	pros::delay(15);
// 	model -> forward(-50);
// 	pros::delay(50);
// 	model -> forward(-90);
// 	pros::delay(50);
// 	model -> forward(-100);
// 	pros::delay(250);
// 	model -> forward(50);
// 	pros::delay(180);
// 	model -> forward(15);
// 	pros::delay(15);
// 	model -> forward(50);
// 	pros::delay(50);
// 	model -> forward(90);
// 	pros::delay(50);
// 	model -> forward(100);
// 	pros::delay(100);
// 	model -> forward(100);
// 	pros::delay(200);








// 	model -> forward(-50);
// 	pros::delay(180);
// 	model -> forward(-15);
// 	pros::delay(15);
// 	model -> forward(-50);
// 	pros::delay(50);
// 	model -> forward(-90);
// 	pros::delay(50);
// 	model -> forward(-100);
// 	pros::delay(250);
//
// 	model -> forward(100);
// 	pros::delay(300);
//
//
//
//
//
// 	intakeRight.move_relative(3000, 100);
// 	intakeLeft.move_relative(-3000, 100);
// 	chassis -> turnAngle(-12_deg);
// 	chassis->moveDistance(0.7_ft);
// 	blooper = 127;
// 	indexer = -127;
// 	pros::delay(2000);
// 	blooper = 0;
// 	indexer = -0;
// 	chassis->driveToPoint({6_ft, 9.5_ft},true);
// 	pros::delay(1000);
// 	chassis->driveToPoint({10_ft, 2_ft});
// 	intakeRight.move_relative(-5000, 600);
// 	intakeLeft.move_relative(5000, 600);
// 	blooper = 127;
// 	indexer = -127;
// 	pros::delay(1500);
// 	intakeRight.move_relative(3000, 100);
// 	intakeLeft.move_relative(-3000, 100);
// 	blooper = 0;
// 	indexer = -0;
//
// //field reset code
// 	pros::delay(300);
// 	model -> strafe(-100);
// 	pros::delay(300);
// 	model -> strafe(-20);
// 	pros::delay(300);
//
//
// 	model -> forward(20);
// 	pros::delay(800);
// 	model -> rotate(50);
// 	pros::delay(800);
//
// 	blooper = 127;
// 	indexer = -127;
// 	pros::delay(1500);
// 	blooper = 0;
// 	indexer = -0;
// 	model -> forward(-15);
// 	pros::delay(15);
// 	model -> forward(-50);
// 	pros::delay(50);
// 	model -> forward(-90);
// 	pros::delay(50);
// 	model -> forward(-100);
// 	pros::delay(300);





	//
	// chassis->turnToPoint({12_ft, 0_ft});
	// model -> forward(15);
	// pros::delay(15);
	// model -> forward(50);
	// pros::delay(50);
	// model -> forward(90);
	// pros::delay(50);
	// model -> forward(100);
	// pros::delay(300);
	// blooper = 127;
	// indexer = -127;
	// pros::delay(1500);
	// blooper = 0;
	// indexer = -0;
	// model -> forward(-15);
	// pros::delay(15);
	// model -> forward(-50);
	// pros::delay(50);
	// model -> forward(-90);
	// pros::delay(50);
	// model -> forward(-100);
	// pros::delay(300);



	//may need to turni






//	intakeRight.move_relative(3000, 100);
	//intakeLeft.move_relative(-3000, 100);






















	// chassis->driveToPoint({2_ft, 10_ft});
	// chassis->turnToPoint({6_ft, 8_ft});
	// chassis->driveToPoint({6_ft, 8_ft});
	//
	// chassis->turnToPoint({6_ft, 6.5_ft});
	// chassis->driveToPoint({6_ft, 6.5_ft});
	//
	// chassis->moveDistance(-1_ft);
	// chassis->moveDistance(1_ft);
	// chassis->moveDistance(-1_ft);
	// chassis->moveDistance(1_ft);




	//sets the state as near the mid globals

	// starts the blooper to release the ball
  //start intakes to flip out
	//start moving to next point
	//(gets to point)
	// and makes the intakes open wide
 //makes the elevator go full powerReverse
 //				perhaps close on the ball but it should work without aswell
 // stops in front of the goal
 //intakes finish off their spinning and ball goes in
 // intakes and stuff stop
 // robot backs up near middle
 // intakes open
 // robot goes forward and intakes
 // intakes and stuff close around ball and it moves a bit
// elevator moves and it goes into goal
//robot backs up






	//start the intakes to put them in front of the bot

	//while intakes are being release the bot is driving to prime for left goal

	// get to turn spot and turni






	/*
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
	*/




	//while(left_bumper.get_value() == 0){
		//blooper = 100;
	//	pros::delay(50);}
	//	chassis->moveDistance(-0.40_ft);

	// pros::delay(110);
	// blooper.move_relative(2000, 600);
	//
	// pros::delay(110);
	// chassis->moveDistance(-0.40_ft);
	// blooper = 127;
	// indexer = -127;
	// pros::delay(120);
	// chassis->moveDistance(4.65_ft);
	// pros::delay(100);
	//
	//
	// chassis -> turnAngle(124_deg);
	// pros::delay(125);
	// setIntakeLeft(-127);
	// setIntakeRight(-127);
	//
	// //intakeRight = -127;
	// //	intakeLeft = 127;
	// chassis -> moveDistance(1.96_ft);
	//
	// pros::delay(15);
	//
	// chassis -> moveDistance(-0.05_ft);
	//
	// pros::delay(1200);
	// setIntakeLeft(0);
	// setIntakeRight(0);
	// chassis -> moveDistance(-1.8_ft);
	//
	//
	// pros::delay(10000);
	// chassis -> moveDistance(-0.05_ft);


	//auton for mid goal start auton

	//	chassis->setState({5_ft, 10.75_ft, 210_deg});
	//	blooper.move_relative(400, 100);
	//	pros::delay(400);
	//	chassis -> driveToPoint({3_ft, 9_ft});
	//chassis -> turnToPoint({0_ft, 12_ft});



	//	chassis->setState({2_ft, 8_ft, 0_deg});
	//blooper.move_relative(400, 100);
	//pros::delay(400);
	//	chassis -> driveToPoint({8_ft, 8_ft});
	//chassis -> driveToPoint({2_ft, 8_ft});


	//intakeRight.move_relative(-30000, 600);
	//intakeLeft.move_relative(30000, 600);
	//chassis -> driveToPoint({5_ft, 7_ft},true);

	/*
	chassis -> driveToPoint({2_ft, 10_ft});
	chassis -> turnToPoint({0_ft, 12_ft});
	blooper = 127;
	indexer = -127;
	chassis -> driveToPoint({1.4_ft, 10.6_ft});
	intakeRight.move_relative(-30000, 100);
	intakeLeft.move_relative(30000, 100);
	chassis -> driveToPoint({0.7_ft, 11.5_ft});
	chassis->moveDistance(-0.07_ft);
	chassis->moveDistance(0.07_ft);
	chassis->moveDistance(-0.07_ft);
	chassis->moveDistance(0.07_ft);
	chassis->moveDistance(-0.07_ft);
	chassis->moveDistance(0.07_ft);
	chassis->moveDistance(-0.07_ft);
	*/







	//chassis -> turnToPoint({2_ft, 10_ft});
	//chassis -> driveToPoint({1_ft, 11_ft});
