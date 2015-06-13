/*
 * PathPlanner.cpp
 *
 *  Created on: Jun 7, 2015
 *      Author: user
 */

#include "PathPlanner.h"
#include <stdlib.h>
#include <math.h>

PathPlanner::PathPlanner(vector<vector<grid_data> > grid, cell_coordinate start, cell_coordinate goal){
	_grid = grid;
	_start = start;
	_goal = goal;
	_open_list.resize( _grid.size() * (_grid[1]).size());
}

double PathPlanner::heuristic_cost_estimate(cell_coordinate cell_from){
	int dx = abs(cell_from.x_Coordinate - _goal.x_Coordinate);
	int dy = abs(cell_from.y_Coordinate - _goal.y_Coordinate);
	double multiple_coordinates = dx^2 + dy^2;
    return sqrt (multiple_coordinates);
}

double PathPlanner::g_cost(cell_coordinate cell_from, cell_coordinate cell_to)
{
	if(( cell_from.x_Coordinate != cell_to.x_Coordinate) && ( cell_from.y_Coordinate != cell_to.y_Coordinate))
		{
			return (_grid[cell_from.x_Coordinate][cell_from.y_Coordinate].g_val + 14);
		}
		else
		{
			return (_grid[cell_from.x_Coordinate][cell_from.y_Coordinate].g_val + 10);
		}
}


void PathPlanner::fill_heuristic( )
{
	for (int i = 0; i < _grid.size(); i++)
	{
		for(int j = 0; j< _grid[i].size(); j++)
		{
			if(_grid[i][j].cell_color == 0){
				cell_coordinate cl(i, j);
				_grid[i][j].h_val = heuristic_cost_estimate(cl);
			}
		}
	}
}

void PathPlanner::fill_g_f(cell_coordinate cell_from){
	int i,j;
	double currentGval;
	bool in_close_list = 0;

	for(i=cell_from.y_Coordinate-1; i <=cell_from.y_Coordinate+1; i++)
	{
		for(j=cell_from.x_Coordinate-1; j <= cell_from.x_Coordinate+1; j++)
		{
			if((i>=0)&&(j>=0)&&(i<_grid.size())&&(j<_grid.size()))
			{
				if((_grid[i][j].g_val == 0)&&(_grid[i][j].cell_color == 0)&&
				   (j != cell_from.x_Coordinate)&&(i != cell_from.y_Coordinate))
				{
					for (int k = 0; ((k < _close_list.size()) && (in_close_list == 0)); k++) {
						if ((_close_list[k].x_Coordinate == _grid[i][j].current.x_Coordinate) &&
							(_close_list[k].y_Coordinate == _grid[i][j].current.y_Coordinate) ) {
							in_close_list = 1;
						}
					}

					if (in_close_list != 1) {
						cell_coordinate cl(i, j);
						currentGval = g_cost(cell_from, cl);
						if((_grid[i][j].g_val > currentGval) || (_grid[i][j].g_val == 0)){
							_grid[i][j].g_val = currentGval;
							_grid[i][j].f_val = _grid[i][j].g_val + _grid[i][j].h_val;
							_grid[i][j].parent.x_Coordinate = cell_from.x_Coordinate;
							_grid[i][j].parent.y_Coordinate = cell_from.y_Coordinate;
						}
					}
					in_close_list = 0;
				}
			}
		}
	}
}

PathPlanner::~PathPlanner() {
	// TODO Auto-generated destructor stub
}

vector<cell_coordinate> PathPlanner::astar()
{
	this->fill_heuristic();
	this->fill_g_f(_start);

	int close_index = 0;

	_open_list[0] = _start;

	while (!_open_list.empty())
	{
		int curr_lowest_f = find_lowest_f_score();
		if ((_open_list[curr_lowest_f].x_Coordinate == _goal.x_Coordinate) &&
		    (_open_list[curr_lowest_f].y_Coordinate == _goal.y_Coordinate))
		{
			reconstruct_path();
			return _path;
		}
		vector<cell_coordinate>::iterator it_openlist;
		vector<cell_coordinate>::iterator it_closelist;
		_close_list[close_index] = _open_list[curr_lowest_f];
		_open_list.erase(it_openlist+curr_lowest_f);

	}

	return _path;
}
int PathPlanner::find_lowest_f_score(){
	int min_index = 0;

	for(int i = 1; i < _open_list.size(); i++)
	{
		if((_grid[_open_list[i].x_Coordinate][_open_list[i].y_Coordinate]).f_val <
			(_grid[_open_list[min_index].x_Coordinate][_open_list[min_index].y_Coordinate]).f_val)
		{
			min_index = i;
		}
	}

	return min_index;
}

void PathPlanner::reconstruct_path()
{
	double current_x_coordinate, current_y_coordinate;
	int i = 0;
	vector<cell_coordinate> path;
	current_x_coordinate = _goal.x_Coordinate;
	current_y_coordinate = _goal.y_Coordinate;

	cell_coordinate currCell(current_x_coordinate, current_y_coordinate);
	path[i] = currCell;
	while ((current_x_coordinate != _start.x_Coordinate)&&(current_y_coordinate != _start.y_Coordinate)){
		i++;
		current_x_coordinate = _grid[current_x_coordinate][current_y_coordinate].parent.x_Coordinate;
		current_y_coordinate = _grid[current_x_coordinate][current_y_coordinate].parent.y_Coordinate;
		cell_coordinate currCell(current_x_coordinate, current_y_coordinate);
		path[i] = currCell;
	}

	cell_coordinate currCell2(_start.x_Coordinate, _start.y_Coordinate);
	path[i+1] = currCell2;

	for (int j = path.size() - 1; j == 0; j--){
		_path[path.size() -1 - j] = path[j];
	}
}
