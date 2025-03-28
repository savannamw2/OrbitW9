//void kill() {}
//void virtual draw(ogstream& gout) const {}
//void virtual destroy(std::vector <Satellite> satellites) {}
//void virtual move(float time) {}
//void virtual input(Interface& ui) {}
#include "satellite.h"
#include "acceleration.h"



// non-default constructor

Satellite::Satellite(const Position& pos, const Velocity& vel, const Angle& angle, double angularVelocity, double radius)
    : pos(pos), velocity(vel), angle(angle), angularVelocity(angularVelocity), dead(false), radius(radius) {}

Satellite::Satellite(const Position& pos, const Velocity& vel)
    : pos(pos), velocity(vel), angle(), angularVelocity(0.0), dead(false), radius(0.0) {}

Satellite::Satellite(const Satellite& rhs)
    : pos(rhs.pos), velocity(rhs.velocity), angle(rhs.angle), angularVelocity(rhs.angularVelocity), dead(rhs.dead), radius(rhs.radius) {}



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
   
   //reassign gravity to gravity at height
   g = gh;
   
   // direction of pull
   double d = atan2(0 - pos.getMetersX(), 0 - pos.getMetersY());
   
   // velocity
   double ddx = g * sin(d);
   double ddy = g * cos(d);
   Acceleration accel(ddx, ddy);
   
   // update velocity
   velocity.add(accel, time / 2) ;
   
   // update point
   pos.add(accel, velocity, time);
   
   velocity.add(accel, time / 2) ;
}

