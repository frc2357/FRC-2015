#include "Robot.hpp"
#include "WPILib.h"




//const float Robot::Kp = 0.03f;

Robot::Robot()
  : robotDrive(frontLeftChannel, rearLeftChannel,
			   frontRightChannel, rearRightChannel),	// these must be initialized in the same order
	stickLeft(joystickChannel),								// as they are declared above.
	stickRight(joystickChannel2),
	liftEncoder(5, 6, false),
	//gyro(7),
	liftMotor(4)
{
	robotDrive.SetExpiration(0.1);
	robotDrive.SetInvertedMotor(RobotDrive::kFrontRightMotor, true); // invert the left side motors
	robotDrive.SetInvertedMotor(RobotDrive::kRearLeftMotor, false);  // you may need to change or remove this to match your robot
	robotDrive.SetInvertedMotor(RobotDrive::kRearRightMotor, true);

	pressedButton=0;
	liftSetpoint=0;
	rotationAngle=0;
	liftMotor.SetSpeed(0);
	rotation=0;
	strafe=0;
	forward=0;
}



void Robot::Autonomous()
{

}

/**
 * Runs the motors with arcade steering.
 */
void Robot::OperatorControl()
{
	robotDrive.SetSafetyEnabled(false);
	while(IsOperatorControl() && IsEnabled())
	{
		updateJoysticks();
		updateUI();
		updateDrive();
		updateLift();
	}
}

/**
 * Runs during test mode
 */
void Robot::Test()
{

}

void Robot::StartCompetition()
{

}

void Robot::updateJoysticks()
{
	rotation=((stickLeft.GetRawAxis(2)/2)-(stickRight.GetRawAxis(2)/2));
	strafe=((stickRight.GetRawAxis(1)/2)+(stickLeft.GetRawAxis(1)/2));
	forward=((stickRight.GetRawAxis(2)/2)+(stickLeft.GetRawAxis(2)/2));
}

void Robot::updateUI()
{
		if(pressedButton==0  && stickLeft.GetRawButton(LIFTBTN1)==1){
			pressedButton=LIFTBTN1;
		}else if(pressedButton==0 && stickLeft.GetRawButton(LIFTBTN2)==1){
			pressedButton=LIFTBTN2;
		}else if(pressedButton==0 && stickLeft.GetRawButton(LIFTBTN3)==1){
			pressedButton=LIFTBTN3;
		}else if(pressedButton==0 && stickLeft.GetRawButton(LIFTBTN4)==1){
			pressedButton=LIFTBTN4;
		}else if(pressedButton==0 && stickLeft.GetRawButton(LIFTBTN5)==1){
			pressedButton=LIFTBTN5;
		}else if(pressedButton==0 && stickLeft.GetRawButton(LIFTBTNINC)==1){
			pressedButton=LIFTBTNINC;
		}else if(pressedButton==0 && stickLeft.GetRawButton(LIFTBTNDEC)==1){
			pressedButton=LIFTBTNDEC;
		}else if(pressedButton==0 && stickLeft.GetRawButton(LIFTBTNUP)==1){
			pressedButton=LIFTBTNUP;
		}else if(pressedButton==0 && stickLeft.GetRawButton(LIFTBTNDOWN)==1){
			pressedButton=LIFTBTNDOWN;
		}else if(pressedButton!=0 && stickLeft.GetRawButton(LIFTBTN1)!=1 && stickLeft.GetRawButton(LIFTBTN2)!=1
				&& stickLeft.GetRawButton(LIFTBTN3)!=1 && stickLeft.GetRawButton(LIFTBTN4)!=1
				&& stickLeft.GetRawButton(LIFTBTN5)!=1 && stickLeft.GetRawButton(LIFTBTNINC)!=1
				&& stickLeft.GetRawButton(LIFTBTNDEC)!=1 && stickLeft.GetRawButton(LIFTBTNUP)!=1
				&& stickLeft.GetRawButton(LIFTBTNDOWN)!=1){
			pressedButton=0;
		}

		//if(stickLeft.GetRawAxis(5)==0 && stickLeft.GetRawAxis(6)==-1){
			//rotationAngle=0;
		//}else if(stickLeft.GetRawAxis(5)==1 && stickLeft.GetRawAxis(6)==-1){
			//rotationAngle=45;
		//}else if(stickLeft.GetRawAxis(5)==1 && stickLeft.GetRawAxis(6)==0){
			//rotationAngle=90;
		//}else if(stickLeft.GetRawAxis(5)==1 && stickLeft.GetRawAxis(6)==1){
			//rotationAngle=135;
		//}else if(stickLeft.GetRawAxis(5)==0 && stickLeft.GetRawAxis(6)==1){
			//rotationAngle=180;
		//}else if(stickLeft.GetRawAxis(5)==-1 && stickLeft.GetRawAxis(6)==1){
			//rotationAngle=225;
		//}else if(stickLeft.GetRawAxis(5)==-1 && stickLeft.GetRawAxis(6)==0){
			//rotationAngle=270;
		//}

}

void Robot::updateDrive()
{
	robotDrive.SetSafetyEnabled(false);
	while (IsOperatorControl() && IsEnabled())
	{
		// Use the joystick X axis for lateral movement, Y axis for forward movement, and Z axis for rotation.
		// This sample does not use field-oriented drive, so the gyro input is set to zero.
		robotDrive.MecanumDrive_Cartesian(strafe, forward, rotation);
		Wait(0.005); // wait 5ms to avoid hogging CPU cycles
	}
}

void Robot::updateLift()
{
	//if(pressedButton==LIFTBTN1){
		//liftSetpoint=LIFTPICKUP;
	//}else if(pressedButton==LIFTBTN2){
		//liftSetpoint=LIFTABOVEGROUND;
	//}else if(pressedButton==LIFTBTN3){
		//liftSetpoint=LIFTPLUS1;
	//}else if(pressedButton==LIFTBTN4){
		//liftSetpoint=LIFTPLUS2;
	//}else if(pressedButton==LIFTBTN5){
		//liftSetpoint=LIFTPLUS3;
	//}else if(pressedButton==LIFTBTNINC){
		//liftSetpoint+=LIFTINCREMENT;
	//}else if(pressedButton==LIFTBTNDEC){
		//liftSetpoint-=LIFTINCREMENT;
	//}



	if(pressedButton==LIFTBTNUP){
		liftMotor.SetSpeed(1);
	}else if(pressedButton==LIFTBTNDOWN){
		liftMotor.SetSpeed(-1);
	}else if(pressedButton!=LIFTBTNUP && pressedButton!=LIFTBTNDOWN){
		liftMotor.SetSpeed(0);
	}
}




START_ROBOT_CLASS(Robot);
