/*
 * WaypointsManager.h
 *
 *  Created on: Jun 14, 2015
 *      Author: colman
 */

#ifndef WAYPOINTSMANAGER_H_
#define WAYPOINTSMANAGER_H_

#include <iostream>
#include <vector>
#include "wayPoint.h"
#include "cellcoordinate.h"
using std::vector;

class WaypointsManager {
public:

	vector<wayPoint> wayPoints;
	void build_way_point_vector(int num_of_cells);

private:
	vector<cell_coordinate> astar_path;
	bool is_verticle = 0;

	double calc_yaw(double m, cell_coordinate cell_from, cell_coordinate cell_to);
	WaypointsManager();
	WaypointsManager(vector<cell_coordinate> path);
	double calc_incline(cell_coordinate cell_from, cell_coordinate cell_to);
	virtual ~WaypointsManager();
};

#endif /* WAYPOINTSMANAGER_H_ */


