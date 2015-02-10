/*
 * LiftController.h
 *
 *  Created on: Feb 7, 2015
 *      Author: Robotics
 */

#ifndef SRC_LIFTCONTROLLER_H_
#define SRC_LIFTCONTROLLER_H_

#include "Talon.h"
#include "Encoder.h"
#include "DigitalInput.h"

class LiftController {
public:
	LiftController(int motorChan, int switchChan,
					int encoderChan1, int encoderChan2);
	virtual ~LiftController();

	void SetSpeed(float speed);
	bool IsDown();
	int EncoderGet();

private:
	Talon liftMotor;
	DigitalInput downSwitch;
	Encoder encoder;
};

#endif /* SRC_LIFTCONTROLLER_H_ */
