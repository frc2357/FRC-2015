#include <cmath>
#include "GyroPID.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"

const float GyroPID::GYRO_VALUES_TO_DEGREES = (90.0f / 140.0f); // TODO Tune multiplier

GyroPID::GyroPID(Gyro &gyro) :
		PIDSubsystem("GyroPID", 0.01, 0.0, 0.0), // TODO Tune PID vars
		gyro(gyro)
{
	gyro.SetSensitivity(.0011);
	GetPIDController()->SetInputRange(0, 360);
	GetPIDController()->SetContinuous(true);
	SetSetpoint(0.0);
	rotation = 0;
	Enable();
	LiveWindow* lw = LiveWindow::GetInstance();
	lw->AddActuator("GyroPID", "GyroPID", GetPIDController());
	lw->AddSensor("GyroPID", "Gyro", &gyro);
}

double GyroPID::ReturnPIDInput()
{
	double degrees = gyro.PIDGet() * GYRO_VALUES_TO_DEGREES;
	degrees = fmod(degrees, 360.0);  // Ensure degrees are between 0 and 360
	degrees = (degrees < 0 ? degrees + 360 : degrees);  // Ensure degrees are always positive.

	std::cout << degrees << std::endl;
	return (degrees);
}

void GyroPID::UsePIDOutput(double output)
{
	rotation = (float) -output;
	//std::cout << output << std::endl;
}

void GyroPID::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
}

float GyroPID::GetRotation()
{
	return rotation;
}
