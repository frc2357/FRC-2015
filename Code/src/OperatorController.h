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
	void updateHatSetpoints(Joystick &stick);

private:

	bool isDeadzone(float x, float y);

	DriveController &driveController;
	LiftController &liftController;
	Joystick stickLeft;
	Joystick stickRight;

	float strafe;
	float forward;
	float rotation;
	int hatPosition;

	static const float MAX_ROTATION;
	static const float STICK_DEADZONE;
};

#endif /* SRC_OPERATORCONTROL_H_ */
