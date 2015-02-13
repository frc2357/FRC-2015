/*
 * DriverController.cpp
 *
 *  Created on: Feb 7, 2015
 *      Author: Robotics
 */

#include <DriveController.h>

DriveController::DriveController(int flChan, int blChan, int frChan, int brChan)
  : robotDrive(flChan, blChan, frChan, brChan) {
	robotDrive.SetExpiration(0.1);

	robotDrive.SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
	robotDrive.SetInvertedMotor(RobotDrive::kRearLeftMotor, false);
	robotDrive.SetInvertedMotor(RobotDrive::kRearRightMotor, true);
}

DriveController::~DriveController() {
	// TODO Auto-generated destructor stub
}

void DriveController::SetThrottle(float x, float y, float rotate) {
	robotDrive.MecanumDrive_Cartesian(x, y, rotate);
}

void DriveController::SetSafetyEnabled(bool enabled) {
	robotDrive.SetSafetyEnabled(enabled);
}

void DriveController::SetExpiration(float expiration){
	robotDrive.SetExpiration(expiration);
}
