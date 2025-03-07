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

/****************
 * Satellite Parent Class
 ***********************/
class Satellite
{
public:
   
   Satellite(const Position& pos, const Velocity& velocity, const Angle& angle, double angularVelocity, double radius);
   Satellite(const Position& pos, const Velocity& velocity);
   Satellite(Satellite &rhs);
   
   float getRadius() {return radius;}
   bool isDead() {return true;}
   Position& getPosition() { return pos;}
//   void kill()
   void virtual draw(ogstream& gout) const {}
//   void virtual destroy(std::vector <Satellite> satellites) {}
   void virtual move(float time);
//   void virtual input(Interface& ui) {}
   
private:
   Velocity velocity;
   Position pos; 
   double angularVelocity;
   bool dead;
   float radius;
}
;
