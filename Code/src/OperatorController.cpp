/*
 * OperatorControl.cpp
 *
 *  Created on: Feb 7, 2015
 *      Author: Robotics
 */

#include "OperatorController.h"

OperatorController::OperatorController(DriveController &driveCtlr,
								 LiftController &liftCtlr,
								 int stickLChan, int stickRChan)
	: driveController(driveCtlr),
	  liftController(liftCtlr),
	  stickRight(stickRChan),
	  stickLeft(stickLChan),
	  rotation(0),
	  forward(0),
	  strafe(0){

}

OperatorController::~OperatorController() {
}

void OperatorController::Run() {
	driveController.SetThrottle(strafe/2, forward/2, rotation/2);

	if (stickRight.GetRawButton(3)==1){
		liftController.SetSpeed(1);
	} else if(stickRight.GetRawButton(4)==1){
		liftController.SetSpeed(-1);
	} else {
		liftController.SetSpeed(0);
	}

	rotation=((stickRight.GetY()/2)-(stickLeft.GetY()/2));
	strafe=((stickRight.GetX()/2)+(stickLeft.GetX()/2));
	forward=((stickRight.GetY()/2)+(stickLeft.GetY()/2));

}
