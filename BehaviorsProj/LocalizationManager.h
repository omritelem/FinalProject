/*
 * LocalizationManager.h
 *
 *  Created on: Jun 17, 2015
 *      Author: colman
 */

#ifndef LOCALIZATIONMANAGER_H_
#define LOCALIZATIONMANAGER_H_
#include <list>
#include "Particle.h"

using namespace std;

#define THRESHOLD 0.25
#define STANDARD 0.7

class LocalizationManager {
public:

	LocalizationManager();
    void update(double dX, double dY, double dTeta, double deltaX, double deltaY,
                double deltaTeta, LaserProxy* pLaserProxy);
    Particle* getHighestProbParticle();

private:
    list<Particle> arrParticles;
    Map* map;

    void createChildren(double dX, double dY, double dRange, int nParticlesNum);
	virtual ~LocalizationManager();
};

#endif /* LOCALIZATIONMANAGER_H_ */
