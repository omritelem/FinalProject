/*
 * Robot.cpp
 *
 *  Created on: Dec 14, 2014
 *      Author: user
 */

#include "Robot.h"
#include <math.h>

Robot::Robot(char* ip, int port) {
	_pc = new PlayerClient(ip,port);
	_pp = new Position2dProxy(_pc);
	_lp = new LaserProxy(_pc);

	_pp->SetMotorEnable(true);
	//For fixing Player's reading BUG
	for(int i=0;i<15;i++)
		Read();
}


double Robot::getXpos()
{
	return (_pp->GetXPos())*100;
}

double Robot::getYpos()
{
	return (_pp->GetYPos())*100;
}

double Robot::getYaw()
{
	return 180*(_pp->GetYaw())/M_PI;

}

Robot::~Robot() {
	delete _pc;
	delete _pp;
	delete _lp;
}
