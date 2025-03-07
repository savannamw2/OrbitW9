//
//  satellite.h
//  OrbitSimulatorW9
//
//  Created by savanna on 3/6/25.
//

#pragma once

#include <iostream>
#include <cmath>
#include "velocity.h"
#include "position.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "testSatellite.h"


/****************
 * Satellite Parent Class
 ***********************/
class Satellite
{
public:
   friend TestSatellite
   
   Satellite(const Position& pos, const Velocity& velocity, const Angle& angle, double angularVelocity, double radius);
   Satellite(const Position& pos, const Velocity& velocity);
   Satellite(Satellite &rhs);
   
   float getRadius() {return radius;}
   bool isDead() {return dead;}
   Position& getPosition() { return pos;}
//   void kill() {}
   virtual void draw(ogstream& gout) = 0;
   
//   void virtual destroy(std::vector <Satellite>& satellites) {}
   void virtual move(float time);
//   void virtual input(Interface* ui) {}
   
private:
   Velocity velocity;
   Position pos;
   double angularVelocity;
   bool dead;
   float radius;
}
;
