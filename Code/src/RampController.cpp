/*
 * RampController.cpp
 *
 *  Created on: Feb 16, 2015
 *      Author: Robotics
 */

#include <RampController.h>
#include "WPILib.h"

RampController::RampController(int stickLChan, int stickRChan)
 :  stickLeft(stickLChan),
	stickRight(stickRChan){
	previousThrottleX = 0;
	previousThrottleY = 0;
	previousThrottleRotation = 0;
	maxChange = 0.02;

}

RampController::~RampController() {
	// TODO Auto-generated destructor stub
}

float RampController::GetCurrentStickX(){
	return ((stickRight.GetX()/2)+(stickLeft.GetX()/2));
}

float RampController::GetCurrentStickY(){
	return ((stickRight.GetY()/2)+(stickLeft.GetY()/2));
}

float RampController::GetCurrentStickRotation(){
	return ((stickRight.GetY()/2)-(stickLeft.GetY()/2));
}

float RampController::GetCurrentX(){
	float o = GetCurrentStickX();
	float op = previousThrottleX;
	float d = maxChange;
	if (o > op+d){
		o = op+d;
	} else if(o < op-d){
		o=op-d;
	}
	op = o;
	Wait (0.01);
	return o;
}

float RampController::GetCurrentY(){
	float o = GetCurrentStickY();
	float op = previousThrottleY;
	float d = maxChange;
	if (o > op+d){
		o = op+d;
	} else if(o < op-d){
		o=op-d;
	}
	op = o;
	Wait (0.01);
	return o;
}

float RampController::GetCurrentZ(){
	float o = GetCurrentStickRotation();
	float op = previousThrottleRotation;
	float d = maxChange;
	if (o > op+d){
		o = op+d;
	} else if(o < op-d){
		o=op-d;
	}
	op = o;
	Wait (0.01);
	return o;
}
