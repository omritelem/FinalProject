/*
 * PathPlanner.h
 *
 *  Created on: Jun 7, 2015
 *      Author: user
 */

#ifndef PATHPLANNER_H_
#define PATHPLANNER_H_

#include "Map.h";

class PathPlanner {
public:

	vector<vector<grid_data> > _grid;
	int _x_goal;
	int _y_goal;
	int _x_start;
	int _y_start;

	PathPlanner(vector<vector<grid_data> > grid);
//	(vector<vector<grid_data> > grid, int x_goal, int y_goal, int x_start, int y_start);
//	void a_star(int grid[][], int x_coordinate, int y_coordinate, int x_goal, int y_goal);
	double heuristic_cost_estimate(int x_coordinate, int y_coordinate, int x_goal, int y_goal);
	double g_cost(double g_from, int x_from, int y_from, int x_to, int y_to);
	double total_f(double g_cost, double heurisitic);
	void fill_heuristic();

	virtual ~PathPlanner();
};

#endif /* PATHPLANNER_H_ */
