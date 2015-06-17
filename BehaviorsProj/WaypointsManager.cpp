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

void WaypointsManager::build_way_point_vector(int num_of_cells)
{
	int counter;
	double m = 0;

	// TODO: fill the vector size

	for (int i = 0; i < astar_path.size(); i++)
	{
		if((i == 0) || (counter == num_of_cells))
		{
			// TODO - fiil yaw
			wayPoint wp(astar_path[i].x_Coordinate, astar_path[i].y_Coordinate , 0);
			wayPoints[wayPoints.size()] = wp;
			counter = 0;

			if (i != 0)
			{
				if(astar_path[i].x_Coordinate == astar_path[i-1].x_Coordinate)
				{
					is_verticle = 1;
				}
				else
				{
					is_verticle = 0;
					m = ((astar_path[i].y_Coordinate - astar_path[i-1].y_Coordinate) / (astar_path[i].x_Coordinate - astar_path[i-1].x_Coordinate));
				}
			}
		}
		else if ((astar_path[i].x_Coordinate == astar_path[i-1].x_Coordinate))
		{
			if(is_verticle == 0)
			{
				is_verticle = 1;
				wayPoint wp3(astar_path[i].x_Coordinate, astar_path[i].y_Coordinate , 0);
				wayPoints[wayPoints.size()] = wp3;
				counter = 0;
			}
		}
		else if(i == 1)
		{
			m = ((astar_path[i].y_Coordinate - astar_path[i-1].y_Coordinate) / (astar_path[i].x_Coordinate - astar_path[i-1].x_Coordinate));
		}
		else if((is_verticle == 1) || (m != ((astar_path[i].y_Coordinate - astar_path[i-1].y_Coordinate) / (astar_path[i].x_Coordinate - astar_path[i-1].x_Coordinate))))
		{
			is_verticle == 0;
			m = (astar_path[i].y_Coordinate - astar_path[i-1].y_Coordinate) / (astar_path[i].x_Coordinate - astar_path[i-1].x_Coordinate);
			wayPoint wp2(astar_path[i].x_Coordinate, astar_path[i].y_Coordinate , 0);
			wayPoints[wayPoints.size()] = wp2;
			counter = 0;
		}

		counter++;
	}
}


double WaypointsManager::calc_yaw(double m, cell_coordinate cell_from, cell_coordinate cell_to)
{
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
			return (0);
		}
		else
		{
			return (180);
		}
	}
	else if (m > 0)
	{
		if (cell_to.y_Coordinate > cell_from.y_Coordinate)
		{
			return (atan(m));
		}
		else
		{
			return (180 + atan(m));
		}
	}
	else
	{
		if (cell_to.y_Coordinate > cell_from.y_Coordinate)
		{
			return (90 + atan(m));
		}
		else
		{
			return (360 - atan(m));
		}
	}
}

double WaypointsManager::calc_incline(cell_coordinate cell_from, cell_coordinate cell_to)
{
	is_verticle = 0;
	if(cell_from.x_Coordinate == cell_to.x_Coordinate)
	{
		is_verticle = 1;
	}
	else if (cell_from.y_Coordinate == cell_to.y_Coordinate)
	{
		return 0;
	}
	else
	{
		return(cell_to.y_Coordinate - cell_from.y_Coordinate) / (cell_to.x_Coordinate - cell_from.x_Coordinate);
	}
}

WaypointsManager::WaypointsManager() {
	// TODO Auto-generated constructor stub

}

WaypointsManager::~WaypointsManager() {
	// TODO Auto-generated destructor stub
}

