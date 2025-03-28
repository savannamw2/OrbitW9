//
//  partStarlinkArray.h
//  Obrit
//
//  Created by Isabel Kamphaus on 3/27/25.
//

//
//  partStarlinkBody.h
//  Obrit
//
//  Created by Isabel Kamphaus on 3/27/25.
//

#include "parts.h"


//class TestParts;
class Position;
class Velocity;

class  PartStarlinkArray: public Parts
{
//   friend TestParts;
    
public:
   
    PartStarlinkArray() : Parts() { }
    PartStarlinkArray(const Position& pos, const Velocity& vel);

   virtual void destroy(std::vector<Satellite*>& satellites) override = 0;
    void draw(ogstream& gout) override;
};

