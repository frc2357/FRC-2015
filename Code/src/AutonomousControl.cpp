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
	liftController.SetSpeed(-1.0);
	Wait (1.0);
	liftController.SetSpeed(0.0);
	driveController.SetThrottle(0.0, 0.5, 0.0);
	Wait (4.0);
	driveController.SetThrottle(0.0, 0.0, 0.0);
}

void AutonomousControl::RunModeTwo(){
	liftController.SetSpeed(-1.0);
	Wait (3.0);
	liftController.SetSpeed(0.0);
	driveController.SetThrottle(0.5, 0.0, 0.0);
	Wait (1.0);
	driveController.SetThrottle(0.0, 0.0, 0.0);
	liftController.SetSpeed(1.0);
	Wait (1.5);
	driveController.SetThrottle(0.0, 0.5, 0.0);
	Wait (1.5);
	liftController.SetSpeed(0.0);
	driveController.SetThrottle(0.0, 0.0, 0.0);
}

void AutonomousControl::RunModeThree(){

}

