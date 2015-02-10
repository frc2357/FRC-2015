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
	driveController.SetThrottle(0, -0.5, 0);
	Wait(1.0);
	driveController.SetThrottle(0, 0, 0);
}

void AutonomousControl::RunModeTwo(){

}

void AutonomousControl::RunModeThree(){

}

