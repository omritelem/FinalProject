
#ifndef ROBOT_H_
#define ROBOT_H_

#include <libplayerc++/playerc++.h>
#include "Defines.h"
//#define DISTANCE_FROM_OBSTACLES 0.6

using namespace PlayerCc;
class Robot {

	PlayerClient* _pc;
	Position2dProxy* _pp;
	LaserProxy* _lp;

public:

	double _x;
	double _y;
	double _yaw;

	Robot(char* ip, int port);
	void Read();
	void setSpeed(float xSpeed, float angularSpeed);
	bool isRightFree();
	bool isLeftFree();
	bool isForwardFree();
	LaserProxy* getLaser();
	double getXpos();
	double getYpos();
	double getYaw();
	void setX(double x);
	void setY(double y);
	void setYaw(double yaw);
	float getLaserDistance(int index);
	bool checkRange(int nStart, int nEnd);

	virtual ~Robot();
};

#endif /* ROBOT_H_ */
