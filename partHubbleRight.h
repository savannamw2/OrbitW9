//
//  partHubbleRight.h
//  Obrit
//
//  Created by Isabel Kamphaus on 3/27/25.
//


#include "parts.h"
#include <vector>
#include "satellite.h"

//class TestParts;
class Position;
class Velocity;

class  PartHubbleRight: public Parts
{
//   friend TestParts;
    
public:
   
    PartHubbleRight() : Parts() { }
    PartHubbleRight(const Position& pos, const Velocity& vel);

   virtual void destroy(std::vector<Satellite*>& satellites) override;
    void draw(ogstream& gout) override;
};
