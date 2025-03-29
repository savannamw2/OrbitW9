//
//  partStarlinkArray.h
//  Obrit
//
//  Created by Isabel Kamphaus on 3/27/25.
//


#include "parts.h"
#include "satellite.h"
#include <vector>


//class TestParts;
class Position;
class Velocity;

class  PartStarlinkArray: public Parts
{
//   friend TestParts;
    
public:
   
    PartStarlinkArray() : Parts() { }
    PartStarlinkArray(const Position& pos, const Velocity& vel);

   virtual void destroy(std::vector<Satellite*>& satellites) override ;
    void draw(ogstream& gout) override;
};
