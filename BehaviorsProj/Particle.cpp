/*
 * Particle.cpp
 *
 *  Created on: Jun 17, 2015
 *      Author: colman
 */

#include "Particle.h"

Particle::Particle(double dX, double dY, double dYaw){
    this->d_X = dX;
    this->d_Y = dY;
    this->d_Teta = dYaw;
    this->d_Belief = 1;
}

// This function update the particle according to the delats and the laser
double Particle::update(double deltaX, double deltaY, double deltaTeta , LaserProxy* laser)
{
    // Variable Definition
    double predBel;
    double normalizeFactor = 1.2;

    // Update the particle position
    d_X += deltaX;
    d_Y += deltaY;
    d_Teta += deltaTeta;

    // Guess the probability
    predBel = d_Belief * probMov(deltaX, deltaY, deltaTeta);

    return (normalizeFactor * predBel);
}

int Particle::probMov(double deltaX, double deltaY, double deltaTeta)
{
    double dist = sqrt(pow(deltaX, 2) + pow(deltaY, 2));

    if ((dist < 0.2) && (abs(deltaTeta) < 0.01))
    {
        return 1;
    }

    return 0;
}

// This function is the belief property
double Particle::getBelief()
{
    return (this->d_Belief);
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

