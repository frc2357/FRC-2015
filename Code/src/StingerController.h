/*
 * StingerController.h
 *
 *  Created on: Mar 7, 2015
 *      Author: Robotics
 */

#ifndef SRC_STINGERCONTROLLER_H_
#define SRC_STINGERCONTROLLER_H_

#include "Talon.h"
#include "DigitalInput.h"

class StingerController {
public:
	StingerController(int motorChan, int backSwitchChan);
	virtual ~StingerController();

	void Update();
	void SetSpeed(float speed);

private:
	Talon windowMotor;
	DigitalInput backSwitch;

	float requestedSpeed;
};

#endif /* SRC_STINGERCONTROLLER_H_ */
