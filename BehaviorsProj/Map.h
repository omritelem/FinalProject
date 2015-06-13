/*
 * Map.h
 *
 *  Created on: Jun 2, 2015
 *      Author: colman
 */

#ifndef MAP_H_
#define MAP_H_
#include <iostream>
#include <vector>
#include "cellcoordinate.h"

using std::vector;

struct grid_data
{
	char cell_color;
	double h_val;
	double g_val;
	double f_val;
	cell_coordinate parent;
	cell_coordinate current;

};


class Map {
private:
	void encodeOneStep1(const char* filename, std::vector<unsigned char> image, unsigned width, unsigned height);
	void decodeOneStep1(const char* filename);

public:
	Map(){}
	void thickenMap(const char* filename, int robotLengthCM, int robotWidthCM);
	vector<vector<grid_data> > convertMapToGrid(const char* filename, double map_resolution, double grid_resolution);

	virtual ~Map();
};

#endif /* MAP_H_ */
