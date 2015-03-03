/*
 * DriverController.cpp
 *
 *  Created on: Feb 7, 2015
 *      Author: Robotics
 */

#include <DriveController.h>

DriveController::DriveController(int flChan, int blChan, int frChan, int brChan, int gyroChan)
  : robotDrive(flChan, blChan, frChan, brChan),
	gyro(gyroChan),
	gyroPID(gyro),
	reqX(0),
	reqY(0),
	reqRotate(0){
	robotDrive.SetExpiration(0.1);
	robotDrive.SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
	robotDrive.SetInvertedMotor(RobotDrive::kRearLeftMotor, false);
	robotDrive.SetInvertedMotor(RobotDrive::kRearRightMotor, true);

}

DriveController::~DriveController() {
	// TODO Auto-generated destructor stub
}

void DriveController::SetThrottle(float x, float y) {
	reqX = x;
	reqY = y;
}

double DriveController::GetRotation()
{
	return gyroPID.ReturnPIDInput();
}

void DriveController::SetRotation(float degrees)
{
	reqRotate = degrees;
	gyroPID.SetSetpoint(degrees);
}

void DriveController::SetSafetyEnabled(bool enabled) {
	robotDrive.SetSafetyEnabled(enabled);
}

void DriveController::SetExpiration(float expiration){
	robotDrive.SetExpiration(expiration);
}

void DriveController::UpdateMotors(){
	//std::cout << "UpdateMotors() rotation = " << gyroPID.GetRotation() << std::endl;
	robotDrive.MecanumDrive_Cartesian(reqX, reqY, gyroPID.GetRotation());
}
