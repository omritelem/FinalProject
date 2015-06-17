/*
 * LocalizationManager.cpp
 *
 *  Created on: Jun 17, 2015
 *      Author: colman
 */

#include "LocalizationManager.h"

LocalizationManager::LocalizationManager() {
    Particle* p = new Particle(0, 0, 0);
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
        if (dBelief < THRESHOLD && arrParticles.size() > 1)
        {
            arrParticles.erase(iterator);
        }
        else if (dBelief > STANDARD)
        {
            createChildren(dX, dY, 0.3, 5);
        }

        // Copy the temp iterator
        iterator = tempIterator;
    }
}


void LocalizationManager::createChildren(double dX, double dY, double dRange, int nParticlesNum)
{
    if(arrParticles.size() + nParticlesNum < 100)
        {
            for(int i = 0; i < nParticlesNum; ++ i)
            {
                double randX = ((double) (rand() % 101) / 100.0) * dRange;
                double randY = ((double) (rand() % 101) / 100.0) * dRange;
                double randYaw = ((double) (rand() % 1000) / 1000.0);

                arrParticles.push_front(Particle(dX + randX, dY + randY, randYaw));
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
