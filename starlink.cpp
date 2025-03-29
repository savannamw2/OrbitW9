//
//  GPS.cpp
//  CSE231_Orbit09
//
//  Created by Sara Fisk on 3/6/25.
//


#include "starlink.h"
#include "uiDraw.h"
#include "partStarlinkBody.h"
#include "partStarlinkArray.h"
#include "fragment.h"


void Starlink::draw(ogstream& gout)
{
   gout.drawStarlink(pos, angle.getDegrees());
}

void Starlink::destroy(std::vector <Satellite*>& satellites)
{
   satellites.push_back(new Fragment);
   satellites.push_back(new Fragment);
   satellites.push_back(new PartStarlinkArray());
   satellites.push_back(new PartStarlinkBody());
   
}
