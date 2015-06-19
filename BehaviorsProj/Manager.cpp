/*
 * Manager.cpp
 *
 *  Created on: Dec 21, 2014
 *      Author: user
 */

#include "Manager.h"

Manager::Manager(Robot* robot, Plan* pln, LocalizationManager* l_manager, ConfigurationManager* cm) {
	_robot = robot;
	_curr = pln->getStartPoint();
	_localization_manager = new LocalizationManager();
	_cm = cm;
}
void Manager::run()
{
//	_robot->Read();
//	if(!(_curr->startCond()))
//		return;
//	_curr->action();
//	while(_curr !=NULL)
//	{
//		while(_curr->stopCond() == false)
//		{
//			_curr->action();
//			_robot->Read();
//		}
//		_curr = _curr->selectNext();
//		_robot->Read();
//	}
	// Perform the first behavior of the plan
	_curr->action();

	while(true)
	{
		_robot->Read();

		_robot->setX(_cm->start_x);
		_robot->setY(_cm->start_y);
		_robot->setYaw(_cm->yaw);

		 // If the current behavior can't run
		if(_curr->stopCond())
		{
			// Perform the next behavior according to the plan
			_curr = _curr->selectNextBehavior();

			if (!_curr)
				break;
		}

		_curr->action();

		// Gets the position of the robot
		double x_Coordinate = 0.0;
		double y_Coordinate = 0.0;
		double dTeta = 0.0;

		// Gets the position of the robot after read
		double current_x_coordinate = _robot->getXpos();
		double current_y_coordinate = _robot->getYpos();
		double current_teta = _robot->getYaw();

		double deltaX = current_x_coordinate - x_Coordinate;
		double deltaY = current_y_coordinate - y_Coordinate;
		double deltaTeta = current_teta - dTeta;

		_localization_manager->update(x_Coordinate, y_Coordinate, dTeta, deltaX, deltaY, deltaTeta, _robot->getLaser());

		x_Coordinate = current_x_coordinate;
		y_Coordinate = current_y_coordinate;
		dTeta = current_teta;
	}
}

Manager::~Manager() {
	// TODO Auto-generated destructor stub
}
