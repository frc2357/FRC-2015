/*
 * AutonomousControl.h
 *
 *  Created on: Feb 9, 2015
 *      Author: Robotics
 */

#ifndef SRC_AUTONOMOUSCONTROL_H_
#define SRC_AUTONOMOUSCONTROL_H_

#include "DriveController.h"
#include "LiftController.h"
#include "WPILib.h"

class AutonomousControl {
public:
	AutonomousControl(DriveController &driveCtlr,
			LiftController &liftCtlr);

	void RunModeOne();
	void RunModeTwo();
	void RunModeThree();
	virtual ~AutonomousControl();

private:
	DriveController &driveController;
	LiftController &liftController;

};

#endif /* SRC_AUTONOMOUSCONTROL_H_ */
