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
	requestedX = 0;
	requestedY = 0;
	requestedRotation = 0;
	currentX = 0;
	currentY = 0;
	currentRotation = 0;
	maxChange = 0.02;

}

RampController::~RampController() {
}


float RampController::GetCurrentX(){
	float o = requestedX;
	float op = currentX;
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
	float o = requestedY;
	float op = currentY;
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
	float o = requestedRotation;
	float op = currentRotation;
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

void RampController::ProcessX(){
	// TODO Transfer GetCurrentX code into here. (Nick: use Pseudo-Code email)
}

void RampController::ProcessY(){
	// TODO Transfer GetCurrentY code into here. (Nick: use Pseudo-Code email)
}

void RampController::ProcessRotation(){
	// TODO Transfer GetCurrentRotation code into here. (Nick: use Pseudo-Code email)
}

float RampController::Round(float value){
	if(value!=0){
		return round(value*10.0)/10.0;
	} else {
		return 0;
	}
}

void RampController::Reset(){

}

void RampController::UpdateMotors(){

}
