/*
 * TurnRight.cpp
 *
 *  Created on: Dec 14, 2014
 *      Author: user
 */

#include "TurnRight.h"

bool Behavior::startCond(){

	if(_robot->isRightFree())
		return true;
	else
		return false;
}

bool Behavior::stopCond(){

	if(_robot->isForwardFree())
		return true;
	else
		return false;
}

void Behavior::action(){

	_robot->setSpeed(MOVE_SPEED, TURN_SPEED);
}

TurnRight::TurnRight(Robot* robot):Behavior(robot) {
	// TODO Auto-generated constructor stub
}

TurnRight::~TurnRight() {
	// TODO Auto-generated destructor stub
}

void TurnRight::print()
{
	//cout << "TurnRight..." << endl;
}
