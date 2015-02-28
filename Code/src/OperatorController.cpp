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
	  stickLeft(stickLChan),
	  //rampController(stickLChan, stickRChan),
	  stickRight(stickRChan){
	strafe = 0;
	forward = 0;
	rotation = 0;
}

OperatorController::~OperatorController() {
}

void OperatorController::Run() {

	//rampController.requestedX = ((stickRight.GetX()/2)+(stickLeft.GetX()/2));
	//rampController.requestedY = ((stickRight.GetY()/2)+(stickLeft.GetY()/2));
	//rampController.requestedRotation = ((stickRight.GetY()/2)-(stickLeft.GetY()/2));
	strafe = ((stickRight.GetX()/2)+(stickLeft.GetX()/2));
	forward = ((stickRight.GetY()/2)+(stickLeft.GetY()/2));
	rotation = ((stickRight.GetY()/2)-(stickLeft.GetY()/2));
	//std::cout << liftController.GetHeightValue() << "," << liftController.GetSetpointValue() << std::endl;
	//bool incPressed = false;
	//bool zeroPressed = false;
	std::cout << liftController.GetHeightValue() << std::endl;
	/*if(stickLeft.GetRawButton(7)){
		rampController.Reset();
	};*/

	//driveController.SetThrottle(rampController.currentX/2, rampController.currentY/2, rampController.currentRotation/2);
	driveController.SetThrottle(strafe/2, forward/2, rotation/2);

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

