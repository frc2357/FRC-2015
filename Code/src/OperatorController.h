/*
 * OperatorController.h
 *
 *  Created on: Feb 7, 2015
 *      Author: Robotics
 */

#ifndef SRC_OPERATORCONTROL_H_
#define SRC_OPERATORCONTROL_H_

#include "Joystick.h"
#include "DriveController.h"
#include "LiftController.h"

class OperatorController {
public:
	OperatorController(DriveController &driveCtlr,
					LiftController &liftCtlr,
					int stickLChan,
					int stickRChan);
	virtual ~OperatorController();
	void Run();

private:
	DriveController &driveController;
	LiftController &liftController;
	Joystick stickRight;
	Joystick stickLeft;
	float rotation;
	float forward;
	float strafe;
};

#endif /* SRC_OPERATORCONTROL_H_ */
