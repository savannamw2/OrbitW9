//
//  partHubbleComputer.h
//  OrbitSimulatorW9
//
//  Created by savanna on 3/27/25.
//


#include "parts.h"
#include "satellite.h"
#include <vector>


//class TestParts;
class Position;
class Velocity;

class  PartHubbleComputer: public Parts
{
   
//   friend TestParts;
    
public:
   
    PartHubbleComputer() : Parts() { }
    PartHubbleComputer(const Position& pos, const Velocity& vel);

   virtual void destroy(std::vector<Satellite*>& satellites) override;
    void draw(ogstream& gout) override;
};
