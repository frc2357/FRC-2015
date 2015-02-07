#include "WPILib.h"

#define LIFTBTNUP 3
#define LIFTBTNDOWN 4


/**
 * This is a demo program showing how to use Mecanum control with the RobotDrive class.
 */
class Robot: public SampleRobot
{

    // Channels for the wheels
    const static int frontLeftChannel	= 1;
    const static int rearLeftChannel	= 0;
    const static int frontRightChannel	= 2;
    const static int rearRightChannel	= 3;

    const static int joystickChannel	= 0;

	RobotDrive robotDrive;	// robot drive system
	Joystick stickLeft;			// only joystick
	Talon liftMotor;
	Joystick stickRight;
	DigitalInput jackIsDown;

	int pressedButton;
	float rotation;
	float forward;
	float strafe;
	bool isDown;

public:
	Robot() :
			robotDrive(frontLeftChannel, rearLeftChannel,
					   frontRightChannel, rearRightChannel),	// these must be initialized in the same order
			stickLeft(joystickChannel),								// as they are declared above.
			liftMotor(4),
			stickRight(1),
			jackIsDown(1)
	{
		robotDrive.SetExpiration(0.1);
		robotDrive.SetInvertedMotor(RobotDrive::kFrontRightMotor, true);	// invert the left side motors
		robotDrive.SetInvertedMotor(RobotDrive::kRearLeftMotor, false);// you may need to change or remove this to match your robot
		robotDrive.SetInvertedMotor(RobotDrive::kRearRightMotor, true);

		pressedButton=0;
		rotation=0;
		forward=0;
		strafe=0;
		isDown=false;
	}

	/**
	 * Runs the motors with Mecanum drive.
	 */
	void Autonomous()
	{
		while (IsAutonomous() && IsEnabled())
		robotDrive.MecanumDrive_Cartesian(0.0,-0.125,0.0);
		Wait(4.0);
		robotDrive.MecanumDrive_Cartesian(0.0,0.0,0.0);
	}

	void OperatorControl()
	{
		std::cout << "Starting Operator Control..." << std::endl;
		robotDrive.SetSafetyEnabled(false);
		while (IsOperatorControl() && IsEnabled())
		{
        	// Use the joystick X axis for lateral movement, Y axis for forward movement, and Z axis for rotation.
        	// This sample does not use field-oriented drive, so the gyro input is set to zero.
			robotDrive.MecanumDrive_Cartesian((strafe)/2, (forward)/2, (rotation)/2);

			Wait(0.005); // wait 5ms to avoid hogging CPU cycles

			if(stickRight.GetRawButton(3)==1 && isDown==false){
				liftMotor.SetSpeed(1);

				}else if(stickRight.GetRawButton(4)==1){
					liftMotor.SetSpeed(-1);
				}else {
					liftMotor.SetSpeed(0);
				}

			rotation=((stickLeft.GetY()/2)-(stickRight.GetY()/2));
			strafe=((stickRight.GetX()/2)+(stickLeft.GetX()/2));
			forward=((stickRight.GetY()/2)+(stickLeft.GetY()/2));

			isDown=(jackIsDown.Get()==1);
		}

	}

};

START_ROBOT_CLASS(Robot);
