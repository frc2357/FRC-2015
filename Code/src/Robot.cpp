#include "WPILib.h"
#include "DriveController.h"

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

	Joystick stickLeft;
	Talon liftMotor;
	Joystick stickRight;
	DigitalInput jackIsDown;
	DriveController driveController;

	int pressedButton;
	float rotation;
	float forward;
	float strafe;
	bool isDown;

public:
	Robot() :
			stickLeft(joystickChannel),								// as they are declared above.
			liftMotor(4),
			stickRight(1),
			jackIsDown(1),
			driveController(1, 0, 2, 3)
	{
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

	}

	void OperatorControl()
	{

		std::cout << "Starting Operator Control..." << std::endl;
		driveController.SetSafetyEnabled(false);
		while (IsOperatorControl() && IsEnabled())
		{
        	// Use the joystick X axis for lateral movement, Y axis for forward movement, and Z axis for rotation.
        	// This sample does not use field-oriented drive, so the gyro input is set to zero.
			driveController.SetThrottle(strafe/2, forward/2, rotation/2);

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
