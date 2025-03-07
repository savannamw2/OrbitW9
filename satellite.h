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
   Satellite();
   
   float getRadius() {return radius;}
//   bool isDead() {return dead;}
   pos& getPosition() { return position;}
   
   void virtual draw(ogstream& gout) const
   {}
   
   
   
   
   
   
   
   
   
private:
   Velocity velocity;
   Position pos; 
   double angularVelocity;
   bool dead;
   float radius;
   
}
