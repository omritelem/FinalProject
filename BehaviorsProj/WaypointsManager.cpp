/*
 * WaypointsManager.cpp
 *
 *  Created on: Jun 14, 2015
 *      Author: colman
 */

#include "WaypointsManager.h"

WaypointsManager::WaypointsManager(vector<cell_coordinate> path)
{
	astar_path = path;
}

void WaypointsManager::build_way_point_vector(int num_of_cells)
{
	int counter;
	double m = 0;
	bool is_vertical = 0;

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
					is_vertical = 1;
				}
				else
				{
					is_vertical = 0;
					m = ((astar_path[i].y_Coordinate - astar_path[i-1].y_Coordinate) / (astar_path[i].x_Coordinate - astar_path[i-1].x_Coordinate));
				}
			}
		}
		else if ((astar_path[i].x_Coordinate == astar_path[i-1].x_Coordinate))
		{
			if(is_vertical == 0)
			{
				is_vertical = 1;
				wayPoint wp3(astar_path[i].x_Coordinate, astar_path[i].y_Coordinate , 0);
				wayPoints[wayPoints.size()] = wp3;
				counter = 0;
			}
		}
		else if(i == 1)
		{
			m = ((astar_path[i].y_Coordinate - astar_path[i-1].y_Coordinate) / (astar_path[i].x_Coordinate - astar_path[i-1].x_Coordinate));
		}
		else if((is_vertical == 1) || (m != ((astar_path[i].y_Coordinate - astar_path[i-1].y_Coordinate) / (astar_path[i].x_Coordinate - astar_path[i-1].x_Coordinate))))
		{
			is_vertical == 0;
			m = (astar_path[i].y_Coordinate - astar_path[i-1].y_Coordinate) / (astar_path[i].x_Coordinate - astar_path[i-1].x_Coordinate);
			wayPoint wp2(astar_path[i].x_Coordinate, astar_path[i].y_Coordinate , 0);
			wayPoints[wayPoints.size()] = wp2;
			counter = 0;
		}

		counter++;
	}
}

double WaypointsManager::calc_yaw(double m, cell_coordinate cell_from, cell_coordinate cell_to, bool is_verticle)
{

}

WaypointsManager::WaypointsManager() {
	// TODO Auto-generated constructor stub

}

WaypointsManager::~WaypointsManager() {
	// TODO Auto-generated destructor stub
}

