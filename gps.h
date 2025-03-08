//
//  GPS.h
//  CSE231_Orbit09
//
//  Created by Sara Fisk on 3/6/25.
//


#include "satellite.h"


class TestGPS;

class GPS : public Satellite
{
   friend TestGPS;
    
public:
   
    // constructors
   GPS() : Satellite() {radius = 12.0;}
   GPS(const Position& pos, const Velocity& velocity, const Angle & angle, double angularVelocity,  float radius) : Satellite(pos, velocity, angle, angularVelocity, 12.0) {}
    GPS(const Position& pos, const Velocity& velocity) : Satellite(pos, velocity) {}
   GPS(const GPS& rhs);
    
   // implement satellite virtual functions
   void draw(ogstream& gout) override;
    
};
