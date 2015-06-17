/*
 * Particle.h
 *
 *  Created on: Jun 17, 2015
 *      Author: colman
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_
#include "Map.h"
#include "Robot.h"

class Particle {

private:
    // Variables
    double d_X;
    double d_Y;
    double d_Teta;
    double d_Belief;


public:
    Particle(double dX, double dY, double dYaw);

    // Properties
    double getBelief();

    // Methods
    double update(double deltaX, double deltaY, double deltaTeta , LaserProxy* laser);
    int probMov(double deltaX, double deltaY, double deltaTeta);
	virtual ~Particle();
};

#endif /* PARTICLE_H_ */
