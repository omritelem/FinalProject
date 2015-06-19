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
#include<set>
using std::vector;
using std::set;      //

class WaypointsManager {
public:

	set<wayPoint> wayPoints;

	WaypointsManager(vector<cell_coordinate> path);
	void build_way_point_vector(int num_of_cells, int start_yaw);
	virtual ~WaypointsManager();

private:
	vector<cell_coordinate> astar_path;
	bool is_verticle = 0;

	double calc_yaw(double m, cell_coordinate cell_from, cell_coordinate cell_to);
	double calc_incline(cell_coordinate cell_from, cell_coordinate cell_to);

};

#endif /* WAYPOINTSMANAGER_H_ */


