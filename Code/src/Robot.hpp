/*
 * Robot.hpp
 *
 *  Created on: Jan 24, 2015
 *      Author: Robotics
 */

#ifndef SRC_ROBOT_HPP_
#define SRC_ROBOT_HPP_


#include "WPILib.h"

#define LIFTPICKUP 0
#define LIFTABOVEGROUND 0
#define LIFTPLUS1 0
#define LIFTPLUS2 0
#define LIFTPLUS3 0
#define LIFTBTN1 12
#define LIFTBTN2 11
#define LIFTBTN3 10
#define LIFTBTN4 9
#define LIFTBTN5 8
#define LIFTBTNINC 5
#define LIFTBTNDEC 6
#define LIFTINCREMENT int (0)
#define LIFTLVL
#define LIFTBTNUP 3
#define LIFTBTNDOWN 4


class Robot: public SampleRobot
{
public:
    // Channels for the wheels
    const static int frontLeftChannel	= 1;
    const static int rearLeftChannel	= 0;
    const static int frontRightChannel	= 2;
    const static int rearRightChannel	= 3;

    const static int jackChannel        = 4;

    const static int joystickChannel	= 0;
    const static int joystickChannel2   = 1;

	RobotDrive robotDrive;	// robot drive system
	Joystick stickLeft;			// only joystick
	Joystick stickRight;
	Encoder liftEncoder;
	//AnalogInput ultrasonicIn;
	//AnalogOutput ultrasonicOut;
	//Gyro gyro;
	Talon liftMotor;


	const static float Kp;
	int pressedButton;
	int liftSetpoint;
	int rotationAngle;
	float rotation;
	float strafe;
	float forward;

	Robot();
	virtual void Autonomous();
	virtual void OperatorControl();
	virtual void Test();
	virtual void StartCompetition();
	virtual void updateJoysticks();
	virtual void updateUI();
	virtual void updateDrive();
	virtual void updateLift();

};

#endif /* SRC_ROBOT_HPP_ */
