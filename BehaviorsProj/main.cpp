/*
 * main.cpp
 *
 *  Created on: Dec 14, 2014
 *      Author: user
 */
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

	ConfigurationManager cm("/home/colman/Documents/LunaWorkSpace/BehaviorsProj/Configuration");

//	ConfigurationManager* cm("/home/colman/Documents/LunaWorkSpace/BehaviorsProj/Configuration");
// 	ReadConfigurationData("/home/colman/Documents/LunaWorkSpace/BehaviorsProj/Configuration");
//	thickenMap(cm->map_path, cm->robot_length, cm->robot_width);

	Map map;
	map.thickenMap("/home/colman/git/FinalProject/BehaviorsProj/roboticLabMap.png", 12, 12);

	vector<vector<grid_data> > grid	= map.convertMapToGrid("/home/colman/git/FinalProject/BehaviorsProj/roboticLabMap.png", 2.5 ,10);

	PathPlanner pathPlanner( grid );
//	grid , cm.target_x, cm.target_y, cm.start_x, cm.start_y);

 	int i = 5;

 	return 0;
}
