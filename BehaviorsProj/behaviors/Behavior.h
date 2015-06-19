/*
 * Behavior.h
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#ifndef BEHAVIOR_H_
#define BEHAVIOR_H_

#include "../Robot.h"

class Behavior {

private:
	Behavior** _nextBehavior;
	int _behaviorsCount;

protected:
	Robot* _robot;

public:
	Behavior(Robot* robot);
	virtual bool startCond() = 0;
	virtual bool stopCond() = 0;
	virtual void action() = 0;
	void  addNextBehavior(Behavior* behavior);
	Behavior* selectNextBehavior();
	virtual ~Behavior();
};

#endif /* BEHAVIOR_H_ */
