/*
 * PathPlanner.cpp
 *
 *  Created on: Jun 7, 2015
 *      Author: user
 */

#include "PathPlanner.h"
#include <stdlib.h>
#include <math.h>

PathPlanner::PathPlanner(vector<vector<grid_data> > grid){
//(vector<vector<grid_data> > grid, int x_goal, int y_goal, int x_start, int y_start) {
_grid = grid;
//	_x_goal = x_goal;
//	_y_goal = y_goal;
//	_x_start = x_start;
//	_y_start = y_start;
}

//void PathPlanner::a_star(int grid[][], int x_coordinate, int y_coordinate, int x_goal, int y_goal)
//{
//
//}

double PathPlanner::heuristic_cost_estimate(int x_coordinate, int y_coordinate, int x_goal, int y_goal){
	int dx = abs(x_coordinate - x_goal);
	int dy = abs(y_coordinate - y_goal);
	double multiple_coordinates = dx^2 + dy^2;
    return sqrt (multiple_coordinates);
}

double PathPlanner::g_cost(double g_from, int x_from, int y_from, int x_to, int y_to)
{
	if(( x_from != x_to ) && ( y_from != y_to ))
	{
		return (g_from + 14);
	}
	else
	{
		return (g_from + 10);
	}
}

double PathPlanner::total_f(double g_cost, double heurisitic)
{
	return( g_cost + heurisitic);
}

void PathPlanner::fill_heuristic( )
{
	for (int i = 0; i < _grid.size(); i++)
	{
		for(int j = 0; j< _grid[i].size(); j++)
		{
			_grid[i][j].h_val = heuristic_cost_estimate(i, j, _x_goal, _y_goal);
		}
	}
}


PathPlanner::~PathPlanner() {
	// TODO Auto-generated destructor stub
}
