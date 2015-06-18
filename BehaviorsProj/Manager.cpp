/*
 * Manager.cpp
 *
 *  Created on: Dec 21, 2014
 *      Author: user
 */

#include "Manager.h"

Manager::Manager(Robot* robot, Plan* pln, LocalizationManager* manager) {
	_robot = robot;
	_curr = pln->getStartPoint();
	_localization_manager = manager;
}
void Manager::run()
{
	_robot->Read();
	if(!(_curr->startCond()))
		return;
	_curr->action();
	while(_curr !=NULL)
	{
		while(_curr->stopCond() == false)
		{
			_curr->action();
			_robot->Read();
		}
		_curr = _curr->selectNext();
		_robot->Read();
	}
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

	//cout << "max: " << _slamManager->getHighestProbParticle()->getBelief() << endl;
	//_localization_manager->getHighestProbParticle()->map->printMap();
	//_map->update(dX, dY, dTeta, _robot->getLaser());

	//_map->printMap();

	x_Coordinate = current_x_coordinate;
	y_Coordinate = current_y_coordinate;
	dTeta = current_teta;

}

Manager::~Manager() {
	// TODO Auto-generated destructor stub
}
