/*
 * ConfigurationManager.h
 *
 *  Created on: May 29, 2015
 *      Author: user
 */

#ifndef CONFIGURATIONMANAGER_H_
#define CONFIGURATIONMANAGER_H_

#include "Defines.h"

using namespace std;

class ConfigurationManager {
public:
	char file_data[NUM_OF_PROPERTIES][MAX_LINE_LENGTH];
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

	ConfigurationManager();
	virtual ~ConfigurationManager();

private:
	void ReadConfigurationData(const char* configurationPath);
	void convertSizeToCM();
};

#endif /* CONFIGURATIONMANAGER_H_ */
