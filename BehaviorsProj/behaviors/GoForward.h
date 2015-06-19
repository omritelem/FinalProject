/*
 * GoForward.h
 *
 *  Created on: Mar 25, 2014
 *      Author: user
 */

#ifndef GOFORWARD_H_
#define GOFORWARD_H_

#include "Behavior.h"
#include "../Robot.h"

class GoForward: public Behavior {

public:

	GoForward(Robot* robot);
	bool startCond();
	bool stopCond();
	void action();
	void print();
	virtual ~GoForward();
};

#endif /* GOFORWARD_H_ */
