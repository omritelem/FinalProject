
#include "TurnRight.h"

bool TurnRight::startCond(){

	if(_robot->isRightFree())
		return true;
	else
		return false;
}

bool TurnRight::stopCond(){

	if(_robot->isForwardFree())
		return true;
	else
		return false;
}

void TurnRight::action(){

	_robot->setSpeed(0.0, TURN_RIGHT_SPEED);
}

TurnRight::TurnRight(Robot* robot):Behavior(robot) {
	// TODO Auto-generated constructor stub
}

TurnRight::~TurnRight() {
	// TODO Auto-generated destructor stub
}

void TurnRight::print(){
	//cout << "TurnRight..." << endl;
}
