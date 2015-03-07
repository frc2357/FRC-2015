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
const float OperatorController::LIFT_INCREMENT = 10.0f;


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
	hatPosition = 0;
}

OperatorController::~OperatorController() {
}

void OperatorController::Run() {

	updateSetpointButton(stickLeft);

	if(isDeadzone(stickLeft.GetX(), stickLeft.GetY()) &&
	   isDeadzone(stickRight.GetX(), stickRight.GetY()))
	{
		updateHatSetpoints(stickLeft);
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
}

bool OperatorController::isDeadzone(float x, float y)
{
	return(fabs(x) < STICK_DEADZONE && fabs(y) < STICK_DEADZONE);
}



void OperatorController::updateHatSetpoints(Joystick &stick)
{
	if(stick.GetPOV() == 180)
	{
		driveController.SetRotation(0);
	}
	else if(stick.GetPOV() == 0)
	{
		driveController.SetRotation(180);
	}
	else if(stick.GetPOV() == 90)
	{
		driveController.SetRotation(90);
	}
	else if(stick.GetPOV() == 270)
	{
		driveController.SetRotation(270);
	}
}

void OperatorController::updateSetpointButton(Joystick &stick)
{
	std::cout << "encoder: " << liftController.GetHeightValue() << ", setpoint: " << liftController.GetSetpointValue() << std::endl;
	if(stick.GetRawButton(4) == 1)
	{
		liftController.SetHeightValue((liftController.GetHeightValue()) + LIFT_INCREMENT);
	}
	else if(stick.GetRawButton(3) == 1)
	{
		liftController.SetHeightValue((liftController.GetHeightValue()) - LIFT_INCREMENT);
	}
}
