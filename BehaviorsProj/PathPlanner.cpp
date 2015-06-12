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
			if(_grid[i][j].cell_color == 0){
				_grid[i][j].h_val = heuristic_cost_estimate(i, j, _x_goal, _y_goal);
			}
		}
	}
}

void PathPlanner::fill_g(int x_from, int y_from){
	int i,j;
	double currentGval;

	for(i=y_from-1; i <=y_from+1; i++)
	{
		for(j=x_from-1; j <= x_from+1; j++)
		{
			if((i>=0)&&(j>=0)&&(i<_grid.size())&&(j<_grid.size()))
			{
				if((_grid[i][j].g_val == 0)&&(_grid[i][j].cell_color == 0)&&(i != x_from)&&(j != y_from))
				{
					currentGval = g_cost(_grid[x_from][y_from].g_val, x_from, y_from,i,j);
					if((_grid[i][j].g_val > currentGval) || (_grid[i][j].g_val == 0)){
						_grid[i][j].g_val = currentGval;
					}

				}
			}
		}
	}
}




PathPlanner::~PathPlanner() {
	// TODO Auto-generated destructor stub
}
