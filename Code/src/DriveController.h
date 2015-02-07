/*
 * DriverController.h
 *
 *  Created on: Feb 7, 2015
 *      Author: Robotics
 */

#ifndef SRC_DRIVECONTROLLER_H_
#define SRC_DRIVECONTROLLER_H_

#include "RobotDrive.h"

class DriveController {
public:
	DriveController(int flChan, int blChan, int frChan, int brChan);
	virtual ~DriveController();

	void SetThrottle(float x, float y, float rotate);
	void SetSafetyEnabled(bool enabled);

private:
	RobotDrive robotDrive;
};

#endif /* SRC_DRIVECONTROLLER_H_ */
