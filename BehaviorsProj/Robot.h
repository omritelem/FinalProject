/*
 * Robot.h
 *
 *  Created on: Dec 14, 2014
 *      Author: user
 */

#ifndef ROBOT_H_
#define ROBOT_H_

#include <libplayerc++/playerc++.h>
#include "Defines.h"

using namespace PlayerCc;
class Robot {

	PlayerClient* _pc;
	Position2dProxy* _pp;
	LaserProxy* _lp;
	double x;
	double y;
	double yaw;

public:

	Robot(char* ip, int port);
	void Read();
	void setSpeed(float xSpeed, float angularSpeed);
	bool isRightFree();
	bool isForwardFree();
	LaserProxy* getLaser();
	double getXpos();
	double getYpos();
	double getYaw();

	virtual ~Robot();
};

#endif /* ROBOT_H_ */
