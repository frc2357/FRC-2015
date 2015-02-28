/*
 * OperatorControl.cpp
 *
 *  Created on: Feb 7, 2015
 *      Author: Robotics
 */

#include "OperatorController.h"

const float OperatorController::MAX_ROTATION_PER_SECOND = 90.0f;

OperatorController::OperatorController(DriveController &driveCtlr,
								 LiftController &liftCtlr,
								 int stickLChan, int stickRChan)
: driveController(driveCtlr),
  liftController(liftCtlr),
  stickLeft(stickLChan),
  //rampController(stickLChan, stickRChan),
  stickRight(stickRChan),
  gyroTime()
{
	strafe = 0;
	forward = 0;
	rotation = 0;
	gyroTime.Start();
	lastRun = gyroTime.Get();
}

OperatorController::~OperatorController() {
}

void OperatorController::Run() {

	double secondsPassed = (gyroTime.Get() - lastRun);
	float stickDifferential = ((stickRight.GetY()/2)-(stickLeft.GetY()/2));
	float stickForward = ((stickRight.GetY()/2)+(stickLeft.GetY()/2));
	float stickStrafe = ((stickRight.GetX()/2)+(stickLeft.GetX()/2));
	float rotationDegPerSec = stickDifferential * MAX_ROTATION_PER_SECOND;

	driveController.SetRotation(rotationDegPerSec * secondsPassed);
	driveController.SetThrottle(stickStrafe, stickForward);

	//bool incPressed = false;
	//bool zeroPressed = false;
	//std::cout << liftController.GetHeightValue() << std::endl;

	if (stickRight.GetRawButton(3)==1){
		liftController.SetSpeed(1);
	} else if(stickRight.GetRawButton(4)==1){
		liftController.SetSpeed(-1);
	} else {
		liftController.SetSpeed(0);
	}

/*	if (stickLeft.GetRawButton(11)==1){
		if (!zeroPressed){
			zeroPressed = true;
			liftController.SetHeightValue(LiftController::LIFT_TOTE_HEIGHTS::ZERO);
		}
	} else {
		zeroPressed = false;
	}

	if (stickLeft.GetRawButton(12)==1){
		if (!incPressed){
			incPressed = true;
			liftController.IncrementHeight();
		}
	} else {
		incPressed = false;
	}
*/

}

