//
//  GPS.cpp
//  CSE231_Orbit09
//
//  Created by Sara Fisk on 3/6/25.
//


#include "starlink.h"
#include "uiDraw.h"


void Starlink::draw(ogstream& gout)
{
   gout.drawStarlink(pos, angle.getDegrees());
}
