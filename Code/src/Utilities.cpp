/*
 * Utilities.cpp
 *
 *  Created on: Mar 2, 2015
 *      Author: Robotics
 */

#include <Utilities.h>
#include <cmath>

double Utilities::NormalizeRotation(double rotation)
{

		rotation = fmod(rotation, 360.0);  // Ensure degrees are between 0 and 360
		rotation = (rotation < 0 ? rotation + 360 : rotation);  // Ensure degrees are always positive.

		return (rotation);
}
