/*
 * main.cpp
 *
 *  Created on: Dec 14, 2014
 *      Author: user
 */

#include <iostream>
#include "Robot.h"
#include "Manager.h"
#include "Plans/PlnObstacleAvoid.h"
#include "Map.h"
#include "PathPlanner.h"
#include "ConfigurationManager.h"
#include <vector>
#include "WaypointsManager.h"

using namespace std;

void printMatrix(vector<vector<grid_data> > lol);

int main()
{
	ConfigurationManager cm(CONFIGURATION_PATH);
	//Robot robot("localhost",6665, &cm, map._original_grid.size());
	//robot.Read();
	Map map;
	map.thickenMap(cm.map_path, cm.robot_width);
	map.createGrids(cm.map_path, cm.map_resolution, cm.grid_resolution);

	cout << map._original_grid.size() <<  "Grid Row" << endl;

	Robot robot("localhost",6665, &cm, map._original_grid.size());

	printMatrix(map._original_grid);
	for (int var = 0; var < 10; var++) {
		cout << endl << "";
	}
	printMatrix(map._thickened_grid);
	// Running the a* algorithm on the thickened map
	// calculating robot location on grid...
	double resolution_relation = cm.grid_resolution / cm.map_resolution;
	// Location is ROUNDED!!!
	int start_x = cm.start_x / resolution_relation;
	int start_y = cm.start_y / resolution_relation;
	int end_x = cm.target_x / resolution_relation;
	int end_y = cm.target_y / resolution_relation;
	cell_coordinate start_point(start_x, start_y);
	cell_coordinate end_point(end_x, end_y);
	PathPlanner pathPlanner(map._thickened_grid, start_point, end_point);

	vector<cell_coordinate> ass_star_result = pathPlanner.astar();

	cout << "THE RESULT IS: " << ass_star_result.size() << endl;
	for (int i = 0; i < ass_star_result.size(); ++i) {
		cout << ass_star_result[i].x_Coordinate << " " << ass_star_result[i].y_Coordinate << endl;
	}


	WaypointsManager wp(ass_star_result, cm.grid_resolution, cm.map_resolution);
	wp.build_way_point_vector(3);

	wayPoint wpm;
	set<wayPoint>::iterator it;

	for (it = (wp.wayPoints).begin(); it != (wp.wayPoints).end(); ++it) {
//	for (it = (wp.wayPoints).end(); it != (wp.wayPoints).begin(); --it) {
		wpm = *it;
		cout << wpm.x_Coordinate << " " << wpm.y_Coordinate << " " << wpm.yaw << endl;
	}

	PlnObstacleAvoid plnOA(&robot, &wp);
	LocalizationManager lm;
//
//	while(true)
//	    {
//	        robot.Read();
//	        robot.setSpeed(0.25, 0.0);
//	        cout << robot.getXpos() << " " << robot.getYpos() << " " << endl;
//	    }

	Manager manager(&robot, &plnOA, &lm, &cm, &wp);
	manager.run();

	//ConfigurationManager cm("Config_test");

 	int i = 5;

// 	vector<cell_coordinate> bla (10);
// 	vector<cell_coordinate>::iterator it;
//
// 	it = bla.begin();
// 	it = bla.insert(it, cl);
//	it = bla.insert(it, cl1);
//
//	cout<<bla.size();
//	bla.erase(bla.begin()+1);

 	return 0;
}

void printMatrix(vector<vector<grid_data> > lol){
	for (int var = 0; var < lol.size(); ++var) {
		for (int var2 = 0; var2 < lol[var].size(); ++var2) {
			cout << (int)lol[var][var2].cell_color;
			cout << " ";
		}
		cout << endl;
	}
}
