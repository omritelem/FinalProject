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

using namespace std;

int main()
{

//	Robot robot("localhost",6665);
//	robot.Read();
//  PlnObstacleAvoid plnOA(&robot);
//	Manager manager(&robot, &plnOA);
//	manager.run();

	ConfigurationManager cm;

	Map map;
	map.thickenMap(cm.map_path, cm.robot_width);
	map.convertMapToGrid(cm.map_path, cm.map_resolution, cm.grid_resolution);

	cell_coordinate cl(5,5);
	cell_coordinate cl1(1,1);
	cell_coordinate cl2(2,2);
	cell_coordinate cl3(3,3);

	PathPlanner pathPlanner(map._grid ,cl , cl);
//	grid , cm.target_x, cm.target_y, cm.start_x, cm.start_y);

//	for (int var = 0; var < map._grid.size(); ++var) {
//		for (int var2 = 0; var2 < map._grid[var].size(); ++var2) {
//			cout << (int)map._grid[var][var2].cell_color;
//			cout << " ";
//		}
//		cout << endl;
//	}

 	int i = 5;

 	vector<cell_coordinate> bla (10);
 	vector<cell_coordinate>::iterator it;

 	it = bla.begin();
 	it = bla.insert(it, cl);
	it = bla.insert(it, cl1);

	cout<<bla.size();
	bla.erase(bla.begin()+1);

 	return 0;
}
