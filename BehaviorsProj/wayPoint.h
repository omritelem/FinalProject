/*
 * wayPoint.h
 *
 *  Created on: Jun 14, 2015
 *      Author: colman
 */

#ifndef WAYPOINT_H_
#define WAYPOINT_H_

class wayPoint {
public:
	double x_Coordinate;
	double y_Coordinate;
	double yaw;

	wayPoint();
	wayPoint(double x, double y, double yaw_angle);
	virtual ~wayPoint();
};

#endif /* WAYPOINT_H_ */
