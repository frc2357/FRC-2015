/*
 * OperatorControl.cpp
 *
 *  Created on: Feb 7, 2015
 *      Author: Robotics
 */

#include "OperatorController.h"

OperatorController::OperatorController(DriveController &driveCtlr,
								 LiftController &liftCtlr)
	: driveController(driveCtlr),
	  liftController(liftCtlr) {

}

OperatorController::~OperatorController() {
}

