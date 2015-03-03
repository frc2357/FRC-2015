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
#include "RampController.h"
#include "Timer.h"


class OperatorController {
public:
	OperatorController(DriveController &driveCtlr,
					LiftController &liftCtlr,
					int stickLChan,
					int stickRChan);
	virtual ~OperatorController();
	void Run();

private:
	static const float MAX_ROTATION;

	DriveController &driveController;
	LiftController &liftController;
	Joystick stickLeft;
	//RampController rampController;
	Joystick stickRight;

	float strafe;
	float forward;
	float rotation;
};

#endif /* SRC_OPERATORCONTROL_H_ */
