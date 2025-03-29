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
#include "angle.h"
#include "uiDraw.h"
#include "uiInteract.h"
//#include "testSatellite.h"

class TestSatellite;
class TestParts;
class TestFragments;
/****************
 * Satellite Parent Class
 ***********************/
class Satellite
{
public:
   friend TestSatellite;
   friend TestParts;
   friend TestFragments;
   
   Satellite() : pos(), velocity(), angle(), angularVelocity(0.0), dead(false), radius(0.0) {}
   Satellite(const Position& pos, const Velocity& vel, const Angle& angle, double angularVelocity, double radius);
   Satellite(const Position& pos, const Velocity& vel);
   Satellite(const Satellite& rhs);
   
   
   float getRadius() {return radius;}
   bool isDead() {return dead;}
   Position& getPosition() { return pos;}
   void kill() {dead  = true;}
   virtual void draw(ogstream& gout)
   {
      
   }
   
   void virtual input(const Interface* pUI, double time) {}
   void virtual destroy(std::vector <Satellite*>& satellites) {};
   void virtual move(float time);
   
protected:
   Velocity velocity;
   Position pos;
   Angle angle; 
   double angularVelocity;
   bool dead;
   float radius;
}
;
