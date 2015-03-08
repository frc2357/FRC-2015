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
const float OperatorController::STINGER_FOLLOW_UP = 0.075f;
const float OperatorController::STINGER_FOLLOW_DOWN = -0.11f;


OperatorController::OperatorController(DriveController &driveCtlr,
								 LiftController &liftCtlr,
								 StingerController &stingerCtlr,
								 int stickLChan, int stickRChan)
: driveController(driveCtlr),
  liftController(liftCtlr),
  stingerController(stingerCtlr),
  stickRight(stickLChan),
  //rampController(stickLChan, stickRChan),
  stickLeft(stickRChan)
{
	strafe = 0;
	forward = 0;
	rotation = 0;
	hatPosition = 0;
}

OperatorController::~OperatorController() {
}

void OperatorController::Run() {

	std::cout << liftController.GetHeightValue() << std::endl;

	updateSetpointButton(stickRight);

	// Button 7 deploys the stinger.
	if (stickLeft.GetRawButton(3) == 1) {
		stingerController.SetSpeed(-0.25);
	}
	else if (stickLeft.GetRawButton(4) == 1) {
		stingerController.SetSpeed(0.25);
	}
	else if(stickRight.GetRawButton(4) == 1)
	{
		stingerController.SetSpeed(0.25);
	}
	else
	{
		stingerController.SetSpeed(0);
	}



	if(isDeadzone(stickRight.GetX(), stickRight.GetY()) &&
	   isDeadzone(stickLeft.GetX(), stickLeft.GetY()))
	{
		updateHatSetpoints(stickRight);
		driveController.SetThrottle(0, 0);
	} else {
		float stickDifferential = ((stickLeft.GetY()/2)-(stickRight.GetY()/2));
		float stickForward = ((stickLeft.GetY()/2)+(stickRight.GetY()/2));
		float stickStrafe = ((stickLeft.GetX()/2)+(stickRight.GetX()/2));
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
	if(stick.GetRawButton(4) == 1)
	{
		liftController.SetHeightValue((liftController.GetHeightValue()) + LIFT_INCREMENT);
	}
	else if(stick.GetRawButton(3) == 1)
	{
		if(!liftController.IsDown())
			{
				liftController.SetHeightValue((liftController.GetHeightValue()) - LIFT_INCREMENT);
			}
	}
}
