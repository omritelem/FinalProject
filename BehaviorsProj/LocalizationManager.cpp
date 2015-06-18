/*
 * LocalizationManager.cpp
 *
 *  Created on: Jun 17, 2015
 *      Author: colman
 */

#include "LocalizationManager.h"

LocalizationManager::LocalizationManager() {
	cell_coordinate cell(0,0);
    Particle* p = new Particle(cell, 0);
    arrParticles.push_front(*p);
}

// This function runs the particle filter algorithm
void LocalizationManager::update(double dX, double dY, double dTeta, double deltaX, double deltaY,
                double deltaTeta, LaserProxy* pLaserProxy)
{
    // Initialize iterator
    list<Particle>::iterator iterator = arrParticles.begin();

    // Go over all the particles
    while (iterator != arrParticles.end())
    {
        // Calculate the belief
        double dBelief = iterator->update(deltaX, deltaY, deltaTeta, pLaserProxy);

        // Copy the iterator so we can delete the original one if we would need to
        list<Particle>::iterator tempIterator = iterator;
        tempIterator++;

        // Handle the belief
        if (dBelief < THRESHOLD && arrParticles.size() > MIN_PARTICLES_NUM)
        {
            arrParticles.erase(iterator);
        }
        else if (dBelief > STANDARD)
        {
            //createChildren(dX, dY, 0.3, 5);
        	createChildren(dX, dY, PARTICLE_RANGE, PARTICLE_NUM_TO_CREATE);
        }

        // Copy the temp iterator
        iterator = tempIterator;
    }
}

// This function creates new particels to the robot
void LocalizationManager::createChildren(double dX, double dY, double dRange, int nParticlesNum)
{
	// Increase the size of the robot only if its below 100
    if(arrParticles.size() + nParticlesNum < MAX_PARTICLES_NUM)
        {
            for(int i = 0; i < nParticlesNum; ++ i)
            {
            	// Creating random coordinates and yaw
                double randX = ((double) (rand() % 101) / 100.0) * dRange;
                double randY = ((double) (rand() % 101) / 100.0) * dRange;
                double randYaw = ((double) (rand() % 1000) / 1000.0);
                // Create new cell coordiante by new coordinates
                cell_coordinate new_cell(dX + randX, dY + randY);
                arrParticles.push_front(Particle(new_cell, randYaw));
            }
        }
}

// This function return the particle with the highest probability
Particle* LocalizationManager::getHighestProbParticle()
{
    list<Particle>::iterator it;
    it = arrParticles.begin();
    Particle* p = it.operator ->();
    for (it=arrParticles.begin(); it!=arrParticles.end(); ++it){
        if (p->getBelief() < it->getBelief()){
            p = it.operator ->();
        }
    }

    return (p);
}

LocalizationManager::~LocalizationManager() {
	// TODO Auto-generated destructor stub
}
