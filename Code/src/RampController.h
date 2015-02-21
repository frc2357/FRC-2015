/*
 * RampController.h
 *
 *  Created on: Feb 16, 2015
 *      Author: Robotics
 */

#ifndef SRC_RAMPCONTROLLER_H_
#define SRC_RAMPCONTROLLER_H_

#include "Joystick.h"



class RampController {
public:
	RampController(int stickLChan, int stickRChan);
	virtual ~RampController();

	float GetCurrentStickX();
	float GetCurrentStickY();
	float GetCurrentStickRotation();
	float GetCurrentX();
	float GetCurrentY();
	float GetCurrentZ();



	/*float GetCurrentDelta();
	void SetCurrentDelta(float delta);*/

private:
	static const int SPEED_ARRAY_SIZE = 3;
	//float currentDelta;
	float currentSpeedArray[SPEED_ARRAY_SIZE];
	float previousSpeedArray[SPEED_ARRAY_SIZE];
	float previousThrottleX;
	float previousThrottleY;
	float previousThrottleRotation;
	float maxChange;

	Joystick stickLeft;
	Joystick stickRight;

	//float startRampSeconds;
	//float stopRampSeconds;

};

#endif /* SRC_RAMPCONTROLLER_H_ */
