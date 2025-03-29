//
//  ship.cpp
//  OrbitSimulatorW9
//
//  Created by savanna on 3/12/25.
//


#include "ship.h"
#include "uiDraw.h"
#include "projectile.h"
#include "uiInteract.h"





void Ship::draw(ogstream& gout)
{
   gout.drawShip(pos, angle.getRadians(), isThrusting());
}


void Ship::input(const Interface *pUI, double time)
{
   if (pUI -> isLeft())
   {
      angle.add(0.1);
   }
   if (pUI -> isRight())
   {
      angle.add(-0.1);
   }
   if (pUI->isSpace())
   {
      setFiring();
   }

   thrust = pUI -> isDown();
   move(time);
}

bool Ship::isThrusting()
{
   return thrust;
}

void Ship::fire(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new Projectile(*this));
   firing = false;
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
      ddx += thrust * sin(angle.getRadians());
      ddy += thrust * cos(angle.getRadians());
   }
   
   Acceleration accel(ddx, ddy);
   
   
   // update velocity
   velocity.add(accel, time / 2.0);
   
   // update point
   pos.add(accel, velocity, time);
   
   velocity.add(accel, time / 2.0);
}
