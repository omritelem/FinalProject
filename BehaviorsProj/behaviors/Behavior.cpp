/*
 * Behavior.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#include "Behavior.h"

Behavior::Behavior(Robot* robot) {

	_robot = robot;
	_nextBehavior = NULL;
	_behaviorsCount = 0;
}

void Behavior::addNextBehavior(Behavior* behavior){

	Behavior** tempBeh = new Behavior*[_behaviorsCount + 1];

	if (!tempBeh) {
		return;
	}

	int i;
	for (i = 0; i < _behaviorsCount; ++i) {
		tempBeh[i] = _nextBehavior[i];
	}

	tempBeh[i] = behavior;
	delete [] behavior;
	_behaviorsCount++;

	_nextBehavior = tempBeh;
}

Behavior* Behavior::selectNextBehavior(){

	int i;
	for(i=0; i<_behaviorsCount; i++)
		if(_nextBehavior[i]->startCond())
			return _nextBehavior[i];

	return NULL;
}

Behavior::~Behavior() {

	delete [] _nextBehavior;
	delete _robot;
}
