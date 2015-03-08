/*
 * StingerController.cpp
 *
 *  Created on: Mar 7, 2015
 *      Author: Robotics
 */

#include <StingerController.h>

StingerController::StingerController(int motorChan, int awaySwitchChan, int backSwitchChan)
	: windowMotor(motorChan),
	  awaySwitch(awaySwitchChan),
	  backSwitch(backSwitchChan)
{
}

StingerController::~StingerController()
{
}

void StingerController::Update()
{
	std::cout << "away: " << awaySwitch.Get() << ", back: " << backSwitch.Get() << std::endl;
}

void StingerController::SetSpeed(float speed)
{
	windowMotor.SetSpeed(speed);
}
