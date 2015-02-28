#include "LiftPID.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"

LiftPID::LiftPID(Encoder &encoder, Talon &liftMotor, DigitalInput &downSwitch) :
		PIDSubsystem("LiftPID", 0.250, 0.0, 0.0),
		encoder(encoder),
		liftMotor(liftMotor),
		downSwitch(downSwitch)
{
	GetPIDController()->SetContinuous(false);
	encoder.SetReverseDirection(true);
	encoder.SetDistancePerPulse(0.01);
	SetSetpoint(0);
	Enable();
	LiveWindow* lw = LiveWindow::GetInstance();
	lw->AddActuator("LiftPID", "PIDSubsystem", GetPIDController());
}

double LiftPID::ReturnPIDInput()
{
	//std::cout << "encoder: " << encoder.PIDGet() << ", setpoint: " << GetSetpoint() << std::endl;
	return encoder.PIDGet();
}

void LiftPID::UsePIDOutput(double output)
{
	if(!downSwitch.Get()){
		//std::cout << "PIDOutput: " << output << std::endl;
		liftMotor.PIDWrite((float) output);
	}

}

void LiftPID::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
}
