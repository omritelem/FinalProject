/*
 * cellcoordinate.h
 *
 *  Created on: Jun 13, 2015
 *      Author: colman
 */

#ifndef CELLCOORDINATE_H_
#define CELLCOORDINATE_H_

class cell_coordinate {
public:
	cell_coordinate();
	cell_coordinate(double x, double y);

	double x_Coordinate;
	double y_Coordinate;


	virtual ~cell_coordinate();
};

#endif /* CELLCOORDINATE_H_ */
