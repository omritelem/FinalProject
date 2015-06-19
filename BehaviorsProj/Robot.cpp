
#include "Robot.h"
#include <math.h>

Robot::Robot(char* ip, int port, ConfigurationManager* cm) {

	_pc = new PlayerClient(ip, port);
	_pp = new Position2dProxy(_pc);
	_lp = new LaserProxy(_pc);

	_pp->SetMotorEnable(true);
	//For fixing Player's reading BUG
	for(int i=0;i<15;i++)
		Read();
	_pp->SetOdometry((double)cm->start_x / 100, (double)cm->start_y / 100, cm->yaw * M_PI / 180 );
}

void Robot::Read()
{
	_pc->Read();
}

void Robot::setSpeed(float xSpeed, float angularSpeed) {
	_pp->SetSpeed(xSpeed, angularSpeed);
}

bool Robot::isRightFree() {
	if ((*_lp)[RIGHT_LASER_PROXY_VALUE] > DISTANCE_TOLERANCE)
		return true;
	else
		return false;
}

bool Robot::isLeftFree() {
	if ((*_lp)[LEFT_LASER_PROXY_VALUE] > DISTANCE_TOLERANCE)
		return true;
	else
		return false;
}

bool Robot::isForwardFree() {
	if ((*_lp)[FORWARD_LASER_PROXY_VALUE] > DISTANCE_TOLERANCE)
		return true;
	else
		return false;
}

double Robot::getXpos()
{
	return (_pp->GetXPos())*100;
}

double Robot::getYpos()
{
	return (_pp->GetYPos())*100;
}

double Robot::getYaw()
{
	return 180*(_pp->GetYaw())/M_PI;
}

void Robot::setX(double x){
	_pp->SetOdometry(x/100, _pp->GetYPos(), _pp->GetYaw());
}
void Robot::setY(double y){
	_pp->SetOdometry(_pp->GetXPos(), y/100 ,_pp->GetYaw());
}
void Robot::setYaw(double yaw){
	_pp->SetOdometry(_pp->GetXPos(), _pp->GetYPos() ,_pp->GetYaw());
}

LaserProxy* Robot::getLaser()
{
	return (_lp);
}

float Robot::getLaserDistance(int index)
{
    return _lp->GetRange(index);
}

bool Robot::checkRange(int nStart, int nEnd)
{
    bool is_dis_Good = true;

    for (int index = nStart; (index <= nEnd) && (is_dis_Good); index++)
    {
    	is_dis_Good = (this->getLaserDistance(index) > DISTANCE_TOLERANCE);
    }

    return (is_dis_Good);
}

Robot::~Robot() {
	delete _pc;
	delete _pp;
	delete _lp;
}
