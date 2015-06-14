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

void printMatrix(vector<vector<grid_data> > lol);

int main()
{

//	Robot robot("localhost",6665);
//	robot.Read();
//  PlnObstacleAvoid plnOA(&robot);
//	Manager manager(&robot, &plnOA);
//	manager.run();

	ConfigurationManager cm(CONFIGURATION_PATH);

	Map map;
	map.thickenMap(cm.map_path, cm.robot_width);
	map.createGrids(cm.map_path, cm.map_resolution, cm.grid_resolution);

	cell_coordinate cl(5,5);
	cell_coordinate cl1(1,1);
	cell_coordinate cl2(2,2);
	cell_coordinate cl3(3,3);

	PathPlanner pathPlanner(map._original_grid ,cl , cl);
//	grid , cm.target_x, cm.target_y, cm.start_x, cm.start_y);

	printMatrix(map._original_grid);
	for (int var = 0; var < 10; var++) {
		cout << endl << "";
	}
	printMatrix(map._thickened_grid);


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

void printMatrix(vector<vector<grid_data> > lol){
	for (int var = 0; var < lol.size(); ++var) {
		for (int var2 = 0; var2 < lol[var].size(); ++var2) {
			cout << (int)lol[var][var2].cell_color;
			cout << " ";
		}
		cout << endl;
	}
}
