//
//  ship.cpp
//  OrbitSimulatorW9
//
//  Created by savanna on 3/12/25.
//


#include "ship.h"
#include "uiDraw.h"



void Ship::draw(ogstream& gout)
{
   gout.drawShip(pos, angle.getDegrees(), isThrusting());
}


void Ship::input(const Interface *pUI)
{
   if (pUI -> isLeft())
   {
      angle.add(-1.0);
   }
   if (pUI -> isRight())
   {
      angle.add(1.0);
   }
   
   thrust = pUI -> isDown();
}

bool Ship::isThrusting()
{
   return thrust;
}


void Ship::move(float time)
{
   //   gravity
   double g = 9.80665;

   //   earth radius
   double r = 6378000;
   
   // height above hearth
   double h = sqrt((pos.getMetersX() * pos.getMetersX())
                   + (pos.getMetersY() * pos.getMetersY())) - r;

   // gravity at height
   double gh = g * ( r / (r + h)) * (r / (r + h));
   
   //reassign gravity to gravity at height
   g = gh;
   
   // direction of pull
   double d = atan2(0 - pos.getMetersX(), 0 - pos.getMetersY());
   
   // velocity
   double ddx = g * sin(d);
   double ddy = g * cos(d);
   
   // thrust
   double thrust = 2.0;
   
   if (isThrusting())
   {
      ddx += thrust * sin(d);
      ddy += thrust * cos(d);
   }
   
   Acceleration accel(ddx, ddy);
   
   
   // update velocity
   velocity.add(accel, time);
   
   // update point
   pos.add(accel, velocity, time);
}
