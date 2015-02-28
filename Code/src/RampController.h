/*
 * RampController.h
 *
 *  Created on: Feb 16, 2015
 *      Author: Robotics
 */

#ifndef SRC_RAMPCONTROLLER_H_
#define SRC_RAMPCONTROLLER_H_

#include "Joystick.h"
#include "Math.h"



class RampController {
public:
	RampController(int stickLChan, int stickRChan);
	virtual ~RampController();


	float GetCurrentX();
	float GetCurrentY();
	float GetCurrentZ();
	void ProcessX();
	void ProcessY();
	void ProcessRotation();
	float Round(float value);
	void Reset();
	void UpdateMotors();
	float currentX;
	float currentY;
	float currentRotation;
	float requestedX;
	float requestedY;
	float requestedRotation;



	/*float GetCurrentDelta();
	void SetCurrentDelta(float delta);*/

private:
	static const int SPEED_ARRAY_SIZE = 3;
	//float currentDelta;
	//float currentSpeedArray[SPEED_ARRAY_SIZE];
	//float previousSpeedArray[SPEED_ARRAY_SIZE];


	float maxChange;

	Joystick stickLeft;
	Joystick stickRight;

	//float startRampSeconds;
	//float stopRampSeconds;

};

#endif /* SRC_RAMPCONTROLLER_H_ */
