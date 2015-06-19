/*
 * GoForward.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#include "GoForward.h"
#include <iostream>
#include <math.h>

bool GoForward::startCond()
{
	//return (_robot->checkRange(_robot->getLaserSpec() / 2 - LASER_SPEC_RANGE ,_robot->getLaserSpec() / 2 + LASER_SPEC_RANGE));
}

bool GoForward::stopCond()
{
	return (!startCond());
}

void GoForward::action()
{
	_robot->setSpeed(MOVE_SPEED, 0.0);
}

GoForward::GoForward(Robot* robot):Behavior(robot) {
	// TODO Auto-generated constructor stub

}

GoForward::~GoForward() {
	// TODO Auto-generated destructor stub
}

void GoForward::print()
{
	//cout << "TurnRight..." << endl;
}
