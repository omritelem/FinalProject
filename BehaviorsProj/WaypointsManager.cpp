/*
 * WaypointsManager.cpp
 *
 *  Created on: Jun 14, 2015
 *      Author: colman
 */

#include "WaypointsManager.h"
#include <math.h>

WaypointsManager::WaypointsManager(vector<cell_coordinate> path)
{
	astar_path = path;
}

void WaypointsManager::build_way_point_vector(int num_of_cells, int start_yaw)
{
	set<wayPoint>::iterator iter = wayPoints.begin();
	int counter = 0;
	double m;

	for (int i = 0; i < astar_path.size(); i++)
	{
		if(i == 0)
		{
			m = calc_incline(astar_path[i],astar_path[i+1]);
			wayPoint wp(astar_path[i].x_Coordinate, astar_path[i].y_Coordinate , calc_yaw(m, astar_path[i], astar_path[i+1]));
			wayPoints.insert(iter,wp);
			++iter;
		}
		else if ( i== (astar_path.size() - 1))
		{
			wayPoint wp(astar_path[i].x_Coordinate, astar_path[i].y_Coordinate , calc_yaw(m, astar_path[i-1], astar_path[i]));
			wayPoints.insert(iter,wp);
			++iter;
		}
		else if (counter == num_of_cells)
		{
			m = calc_incline(astar_path[i], astar_path[i+1]);

			wayPoint wp(astar_path[i].x_Coordinate, astar_path[i].y_Coordinate , calc_yaw(m, astar_path[i], astar_path[i+1]));
			wayPoints.insert(iter,wp);
			++iter;
			counter = 0;
		}
		else
		{
			double new_m;
			bool is_old_varticle;
			is_old_varticle = is_verticle;
			new_m = calc_incline(astar_path[i], astar_path[i+1]);
			if((new_m != m)||(is_old_varticle != is_verticle))
			{
				wayPoint wp(astar_path[i].x_Coordinate, astar_path[i].y_Coordinate, calc_yaw(new_m, astar_path[i], astar_path[i+1]));
				wayPoints.insert(iter,wp);
				++iter;
				counter = 0;
			}
			m = new_m;
		}

		counter++;
	}
}

double WaypointsManager::calc_yaw(double m, cell_coordinate cell_from, cell_coordinate cell_to)
{
	double angle;

	if(!is_verticle)
	{
		angle = 180 * atan(m) / M_PI;
	}

	if (is_verticle)
	{
		if (cell_to.y_Coordinate > cell_from.y_Coordinate)
		{
			return (90);
		}
		else
		{
			return (270);
		}
	}
	else if ( m == 0)
	{
		if (cell_to.x_Coordinate > cell_from.x_Coordinate)
		{
			return (angle);
		}
		else
		{
			return (180 + angle);
		}
	}
	else if (m > 0)
	{
		if (cell_to.y_Coordinate > cell_from.y_Coordinate)
		{
			return (angle);
		}
		else
		{
			return (180 + angle);
		}
	}
	else
	{
		if (cell_to.y_Coordinate > cell_from.y_Coordinate)
		{
			return (90 + angle);
		}
		else
		{
			return (360 - angle);
		}
	}
}

double WaypointsManager::calc_incline(cell_coordinate cell_from, cell_coordinate cell_to)
{
	is_verticle = 0;
	if(cell_from.x_Coordinate == cell_to.x_Coordinate)
	{
		is_verticle = 1;
		// TODO- CHECK if ok
		return(9999);
	}
	else
	{
		return((cell_to.y_Coordinate - cell_from.y_Coordinate) / (cell_to.x_Coordinate - cell_from.x_Coordinate));
	}
}


WaypointsManager::~WaypointsManager() {
	// TODO Auto-generated destructor stub
}

