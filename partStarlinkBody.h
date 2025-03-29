//
//  partStarlinkBody.h
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

class  PartStarlinkBody: public Parts
{
//   friend TestParts;
    
public:
   
   PartStarlinkBody() : Parts() { }
   PartStarlinkBody(const Position& pos, const Velocity& vel) : Parts(pos, vel) { this->radius = 2; }

   virtual void destroy(std::vector<Satellite*>& satellites) override;
    void draw(ogstream& gout) override;
};
