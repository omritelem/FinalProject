/*
 * ConfigurationManager.h
 *
 *  Created on: May 29, 2015
 *      Author: user
 */

#include <string>

#ifndef CONFIGURATIONMANAGER_H_
#define CONFIGURATIONMANAGER_H_
#define NUM_READ_LINES 10
#define MAX_LINE_LENGTH 100
//#define CONFIGURA?TION_PATH '/home/user/workspace/Robots/Configuration'

using namespace std;

class ConfigurationManager {
public:
	char file_data[NUM_READ_LINES][100];
	char* map_path;
	int start_x;
	int start_y;
	int yaw;
	int target_x;
	int target_y;
	double robot_length;
	double robot_width;
	double map_resolution;
	double grid_resolution;
	char* configurationPath;

	ConfigurationManager(const char* configurationPath);
	virtual ~ConfigurationManager();

	void ReadConfigurationData(const char* configurationPath);
	void convertSizeToCM();
};

#endif /* CONFIGURATIONMANAGER_H_ */
