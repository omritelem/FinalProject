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

private:
	vector<cell_coordinate> astar_path;

	void build_way_point_vector(int num_of_cells);
	WaypointsManager();
	WaypointsManager(vector<cell_coordinate> path);
	virtual ~WaypointsManager();
};

#endif /* WAYPOINTSMANAGER_H_ */
