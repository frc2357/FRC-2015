/*
 * LiftController.cpp
 *
 *  Created on: Feb 7, 2015
 *      Author: Robotics
 */

#include "LiftController.h"

LiftController::LiftController(int motorChan, int switchChan,
								int encoderChan1, int encoderChan2,
								float p, float i, float d)
	: liftMotor(motorChan),
	  downSwitch(switchChan),
	  encoder(encoderChan1, encoderChan2),
	  presetControl(p, i, d, &encoder, &liftMotor){
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

int32_t LiftController::GetHeightValue(){
	return encoder.Get();
}

void LiftController::SetHeightValue(float encoderValue){
	presetControl.SetSetpoint(encoderValue);
}

void LiftController::StartPID(){
	presetControl.Enable();
}

void LiftController::IncrementHeight(){
	int32_t height = GetHeightValue();
	for(int i=0; i<LIFT_TOTE_HEIGHTS::HEIGHT_MAX; i++){
		if(LIFT_TOTE_HEIGHTS_ARRAY[i]>height){
			SetHeightValue(LIFT_TOTE_HEIGHTS_ARRAY[i]);
			return;
		}
	}
}
