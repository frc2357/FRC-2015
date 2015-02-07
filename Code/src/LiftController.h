/*
 * LiftController.h
 *
 *  Created on: Feb 7, 2015
 *      Author: Robotics
 */

#ifndef SRC_LIFTCONTROLLER_H_
#define SRC_LIFTCONTROLLER_H_

#include "Talon.h"
#include "DigitalInput.h"

class LiftController {
public:
	LiftController(int motorChan, int switchChan);
	virtual ~LiftController();

	void SetSpeed(float speed);
	bool IsDown();

private:
	Talon liftMotor;
	DigitalInput downSwitch;
};

#endif /* SRC_LIFTCONTROLLER_H_ */
