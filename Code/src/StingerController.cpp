/*
 * StingerController.cpp
 *
 *  Created on: Mar 7, 2015
 *      Author: Robotics
 */

#include <StingerController.h>

StingerController::StingerController(int motorChan, int backSwitchChan)
	: windowMotor(motorChan),
	  backSwitch(backSwitchChan)
{
	requestedSpeed = 0;
}

StingerController::~StingerController()
{
}

void StingerController::Update()
{
	//std::cout << "away: " << awaySwitch.Get() << ", back: " << backSwitch.Get() << std::endl;
	if(backSwitch.Get() == 0)
	{
		windowMotor.SetSpeed(-0.25);
	}
	else
	{
		windowMotor.SetSpeed(requestedSpeed);
	}
}

void StingerController::SetSpeed(float speed)
{
	requestedSpeed = speed;
}
