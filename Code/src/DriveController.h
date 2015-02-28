/*
 * DriverController.h
 *
 *  Created on: Feb 7, 2015
 *      Author: Robotics
 */

#ifndef SRC_DRIVECONTROLLER_H_
#define SRC_DRIVECONTROLLER_H_

#include "RobotDrive.h"
#include "Subsystems/GyroPID.h"
#include "Gyro.h"

class DriveController {
public:
	DriveController(int flChan, int blChan, int frChan, int brChan, int gyroChan);
	virtual ~DriveController();

	void SetThrottle(float x, float y);
	void SetRotation(float degrees);
	void SetSafetyEnabled(bool enabled);
	void SetExpiration(float expiration);
	void UpdateMotors();

private:
	RobotDrive robotDrive;
	Gyro gyro;
	GyroPID gyroPID;


	float reqX;
	float reqY;
	float reqRotate;
};

#endif /* SRC_DRIVECONTROLLER_H_ */
