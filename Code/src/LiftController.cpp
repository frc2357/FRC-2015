/*
 * LiftController.cpp
 *
 *  Created on: Feb 7, 2015
 *      Author: Robotics
 */

#include "LiftController.h"

LiftController::LiftController(int motorChan, int switchChan,
								int encoderChan1, int encoderChan2)
	: liftMotor(motorChan),
	  downSwitch(switchChan),
	  encoder(encoderChan1, encoderChan2){
}


LiftController::~LiftController() {
}

void LiftController::SetSpeed(float speed) {
	if (IsDown() && speed > 0) {
		speed = 0;
		encoder.Reset();
	}
	liftMotor.SetSpeed(speed);
}

bool LiftController::IsDown() {
	return (downSwitch.Get() == 1);
}

int LiftController::EncoderGet(){
	return encoder.Get();
}

