//
//  dragon.h
//  CSE231_Orbit09W10
//
//  Created by Sara Fisk on 3/13/25.
//

#include "satellite.h"


class TestDragon;

class Dragon : public Satellite
{
   friend TestDragon;
    
public:
   
    // constructors
   Dragon() : Satellite() {radius = 7.0;}
   Dragon(const Position& pos, const Velocity& velocity, const Angle & angle, double angularVelocity,  float radius) : Satellite(pos, velocity, angle, angularVelocity, 7.0) {}
   Dragon(const Position& pos, const Velocity& velocity) : Satellite(pos, velocity) {}
   Dragon(const Dragon& rhs);
    
   // implement satellite virtual functions
   void draw(ogstream& gout) override;
   void virtual destroy(std::vector <Satellite*>& satellites) override;


};
