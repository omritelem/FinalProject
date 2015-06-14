/*
 * Map.h
 *
 *  Created on: Jun 2, 2015
 *      Author: colman
 */

#ifndef MAP_H_
#define MAP_H_

#include "Defines.h"
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
	void encodeOneStep(const char* filename, std::vector<unsigned char> image, unsigned width, unsigned height);
	void decodeOneStep(const char* filename);

public:
	vector<vector<grid_data> > _grid;

	Map(){}
	void thickenMap(const char* filename, int thickenSizeCM);
	void convertMapToGrid(const char* filename, double map_resolution, double grid_resolution);

	virtual ~Map();
};

#endif /* MAP_H_ */
