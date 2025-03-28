//
//  parts.h
//  OrbitSimulatorW9
//
//  Created by savanna on 3/27/25.
//


#include "satellite.h"


//class TestParts;
class Position;
class Velocity;

class Parts : public Satellite
{
//   friend TestParts;
    
public:
   
   Part() : Satellite() { }
   Part(const Position& pos, const Velocity& vel);

   virtual void destroy(std::vector<Satellite*>& satellites) override = 0;
   
};

