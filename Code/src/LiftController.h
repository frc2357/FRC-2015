/*
 * LiftController.h
 *
 *  Created on: Feb 7, 2015
 *      Author: Robotics
 */

#ifndef SRC_LIFTCONTROLLER_H_
#define SRC_LIFTCONTROLLER_H_

#include "Talon.h"
#include "Encoder.h"
#include "DigitalInput.h"
#include "PIDController.h"
#include "PIDSource.h"
#include "PIDOutput.h"


class LiftController {
public:
	LiftController(int motorChan, int switchChan,
					int encoderChan1, int encoderChan2,
					float p, float i, float d);
	virtual ~LiftController();

	void SetSpeed(float speed);
	bool IsDown();
	int EncoderGet();
	int32_t GetHeightValue();
	void SetHeightValue(float encoderValue);
	void IncrementHeight();
	void StartPID();


	enum LIFT_TOTE_HEIGHTS{
		ZERO = 0,
		OFF_FLOOR = 1600,
		ABOVE_1 = 4670,
		ABOVE_2 = 9860,
		ABOVE_3 = 16470,
		ABOVE_4 = 29050,
		HEIGHT_MAX = 6
	};
	const LIFT_TOTE_HEIGHTS LIFT_TOTE_HEIGHTS_ARRAY[HEIGHT_MAX] = { ZERO, OFF_FLOOR, ABOVE_1, ABOVE_2, ABOVE_3, ABOVE_4 };


private:
	Talon liftMotor;
	DigitalInput downSwitch;
	Encoder encoder;
	PIDController presetControl;
};

#endif /* SRC_LIFTCONTROLLER_H_ */
