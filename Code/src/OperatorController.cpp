/*
 * OperatorControl.cpp
 *
 *  Created on: Feb 7, 2015
 *      Author: Robotics
 */

#include "OperatorController.h"
#include "Utilities.h"
#include <cmath>

const float OperatorController::MAX_ROTATION = 50.0f;
const float OperatorController::STICK_DEADZONE = 0.1f;

OperatorController::OperatorController(DriveController &driveCtlr,
								 LiftController &liftCtlr,
								 int stickLChan, int stickRChan)
: driveController(driveCtlr),
  liftController(liftCtlr),
  stickLeft(stickLChan),
  //rampController(stickLChan, stickRChan),
  stickRight(stickRChan)
{
	strafe = 0;
	forward = 0;
	rotation = 0;
}

OperatorController::~OperatorController() {
}

void OperatorController::Run() {

	if(isDeadzone(stickLeft.GetX(), stickLeft.GetY()) &&
	   isDeadzone(stickRight.GetX(), stickRight.GetY()))
	{
		driveController.SetThrottle(0, 0);
	} else {
		float stickDifferential = ((stickRight.GetY()/2)-(stickLeft.GetY()/2));
		float stickForward = ((stickRight.GetY()/2)+(stickLeft.GetY()/2));
		float stickStrafe = ((stickRight.GetX()/2)+(stickLeft.GetX()/2));
		double deltaDegrees = stickDifferential * MAX_ROTATION;
		double newSetpoint = Utilities::NormalizeRotation(driveController.GetRotation() + deltaDegrees);
		driveController.SetRotation(newSetpoint);
		driveController.SetThrottle(stickStrafe, stickForward);
	}

	if (stickRight.GetRawButton(3)==1){
		liftController.SetSpeed(1);
	} else if(stickRight.GetRawButton(4)==1){
		liftController.SetSpeed(-1);
	} else {
		liftController.SetSpeed(0);
	}
}

bool OperatorController::isDeadzone(float x, float y)
{
	return(fabs(x) < STICK_DEADZONE && fabs(y) < STICK_DEADZONE);
}

