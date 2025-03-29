//
//  GPS.h
//  CSE231_Orbit09
//
//  Created by Sara Fisk on 3/6/25.
//


#include "satellite.h"


class TestStarlink;

class Starlink : public Satellite
{
   friend TestStarlink;
    
public:
   
    // constructors
   Starlink() : Satellite() {radius = 6.0;}
   Starlink(const Position& pos, const Velocity& velocity, const Angle & angle, double angularVelocity,  float radius) : Satellite(pos, velocity, angle, angularVelocity, 6.0) {}
    Starlink(const Position& pos, const Velocity& velocity) : Satellite(pos, velocity) {}
   Starlink(const Starlink& rhs);
    
   // implement satellite virtual functions
   void draw(ogstream& gout) override;
   void virtual destroy(std::vector <Satellite*>& satellites) override;

};
