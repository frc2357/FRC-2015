/*
 * LiftController.cpp
 *
 *  Created on: Feb 7, 2015
 *      Author: Robotics
 */

#include "LiftController.h"

LiftController::LiftController(int motorChan, int switchChan)
	: liftMotor(motorChan),
	  downSwitch(switchChan) {
}


LiftController::~LiftController() {
}

void LiftController::SetSpeed(float speed) {
	if (IsDown() && speed > 0) {
		speed = 0;
	}
	liftMotor.SetSpeed(speed);
}

bool LiftController::IsDown() {
	return (downSwitch.Get() == 1);
}
