//
//  parts.h
//  OrbitSimulatorW9
//
//  Created by savanna on 3/27/25.
//

#pragma once
#include "satellite.h"
#include <vector>


//class TestParts;
class Position;
class Velocity;
class TestParts;
class TestFragments;

class Parts : public Satellite
{
   friend TestParts;
    friend TestFragments;
    
public:
   
   Parts() : Satellite() { }
   Parts(const Position& pos, const Velocity& vel);

   virtual void destroy(std::vector<Satellite*>& satellites) {};
   
};

