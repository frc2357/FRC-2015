/*
 * AutonomousControl.cpp
 *
 *  Created on: Feb 9, 2015
 *      Author: Robotics
 */

#include <AutonomousControl.h>

AutonomousControl::AutonomousControl(DriveController &driveCtlr,
									LiftController &liftCtlr)
			: driveController(driveCtlr),
			  liftController(liftCtlr)
{

}

AutonomousControl::~AutonomousControl() {
}

void AutonomousControl::RunModeOne(){
	liftController.SetHeightValue(120);
	driveController.SetThrottle(0.0, -0.125);
	driveController.UpdateMotors();
	Wait(0.5);
	driveController.SetThrottle(0.0, 0.5);
	driveController.UpdateMotors();
	Wait(3.0);
	driveController.SetThrottle(0.0, 0.0);
	driveController.UpdateMotors();
	liftController.SetHeightValue(0);
}

void AutonomousControl::RunModeTwo(){

}

void AutonomousControl::RunModeThree(){

}

