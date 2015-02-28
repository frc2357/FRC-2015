#ifndef GyroPID_H
#define GyroPID_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"

class GyroPID: public PIDSubsystem
{
public:
	GyroPID(Gyro &gyro);
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	float GetRotation();

private:
	Gyro &gyro;

	static const float GYRO_VALUES_TO_DEGREES;

	float rotation;
};

#endif
