//
//  GPS.h
//  CSE231_Orbit09
//
//  Created by Savanna on 3/6/25.
//


#include "satellite.h"


//class TestHubble;

class Hubble : public Satellite
{
//   friend TestHubble;
    
public:
   
    // constructors
   Hubble() : Satellite() {radius = 10.0;}
   Hubble(const Position& pos, const Velocity& velocity, const Angle & angle, double angularVelocity,  float radius) : Satellite(pos, velocity, angle, angularVelocity, 10.0) {}
    Hubble(const Position& pos, const Velocity& velocity) : Satellite(pos, velocity) {}
   Hubble(const Hubble& rhs);
    
   // implement satellite virtual functions
   void draw(ogstream& gout) override;
   
   
    
};
