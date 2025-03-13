//
//  ship.h
//  OrbitSimulatorW9
//
//  Created by savanna on 3/12/25.
//

#include "satellite.h"
#include "uiInteract.h"

class Ship : public Satellite
{
public:
   Ship() : Satellite() {};
   Ship(const Position& pos, const Velocity& velocity, const Angle & angle, double angularVelocity,  float radius) : Satellite(pos, velocity, angle, angularVelocity, radius) {};
    Ship(const Position& pos, const Velocity& velocity) : Satellite(pos, velocity) {}
   Ship(const Ship& rhs);

   void draw(ogstream& gout) override;
   
   bool isThrusting();
   
   void input(const Interface *pUI);
   
   void move(float time) override; 

private:
   bool thrust; 
   
   
};
