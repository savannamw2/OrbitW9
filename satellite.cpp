//void kill() {}
//void virtual draw(ogstream& gout) const {}
//void virtual destroy(std::vector <Satellite> satellites) {}
//void virtual move(float time) {}
//void virtual input(Interface& ui) {}
#include "satellite.h"
#include "acceleration.h"


// Move Method
void Satellite::move(float time)
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
   
   // direction of pull
   double d = atan2(0 - pos.getMetersX(), 0 - pos.getMetersY());
   
   // velocity
   double ddx = g * sin(d);
   double ddy = g * cos(d);
   Acceleration accel(ddx, ddy);
   
   // update velocity
   velocity.add(accel, time);
   
   // update point
   pos.add(accel, velocity, time);
}

