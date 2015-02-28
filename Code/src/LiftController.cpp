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
	  encoder(encoderChan1, encoderChan2),
	  liftPID(encoder, liftMotor, downSwitch){
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
	return (downSwitch.Get() == 0);
}


int32_t LiftController::GetHeightValue(){
	return encoder.Get();
}

int LiftController::GetSetpointValue(){
	return liftPID.GetSetpoint();
}

void LiftController::SetHeightValue(float encoderValue){
	liftPID.SetSetpoint(encoderValue);
}

void LiftController::StartPID(){

}

/*void LiftController::IncrementHeight(){
	int32_t height = GetHeightValue();
	for(int i=0; i<LIFT_TOTE_HEIGHTS::HEIGHT_MAX; i++){
		if(LIFT_TOTE_HEIGHTS_ARRAY[i]>height){
			SetHeightValue(LIFT_TOTE_HEIGHTS_ARRAY[i]);
			return;
		}
	}
}*/
void LiftController::StartEncoder(){
	encoder.Reset();
}
