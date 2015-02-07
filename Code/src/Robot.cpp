#include "WPILib.h"
#include "DriveController.h"
#include "LiftController.h"
#include "OperatorController.h"

class OperatrControl {
public:
	OperatrControl();
	virtual ~OperatrControl();
};

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
	Joystick stickRight;
	DriveController driveController;
	LiftController liftController;
	OperatorController operatorControl;

	int pressedButton;
	float rotation;
	float forward;
	float strafe;

public:
	Robot() :
			stickLeft(joystickChannel),
			stickRight(1),
			driveController(1, 0, 2, 3),
			liftController(4, 1),
			operatorControl(driveController, liftController)
	{
		pressedButton=0;
		rotation=0;
		forward=0;
		strafe=0;
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

			if (stickRight.GetRawButton(3)==1){
				liftController.SetSpeed(1);
			} else if(stickRight.GetRawButton(4)==1){
				liftController.SetSpeed(-1);
			} else {
				liftController.SetSpeed(0);
			}

			rotation=((stickLeft.GetY()/2)-(stickRight.GetY()/2));
			strafe=((stickRight.GetX()/2)+(stickLeft.GetX()/2));
			forward=((stickRight.GetY()/2)+(stickLeft.GetY()/2));

		}

	}

};

START_ROBOT_CLASS(Robot);
