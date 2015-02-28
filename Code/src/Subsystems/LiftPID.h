#ifndef LiftPID_H
#define LiftPID_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "Livewindow/LiveWindow.h"

class LiftPID: public PIDSubsystem
{
public:
	LiftPID(Encoder &encoder, Talon &liftMotor, DigitalInput &downSwitch);
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();

private:
	Encoder &encoder;
	Talon &liftMotor;
	DigitalInput &downSwitch;
};

#endif
