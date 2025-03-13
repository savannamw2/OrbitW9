//
//  GPS.cpp
//  CSE231_Orbit09
//
//  Created by Savanna Fisk on 3/6/25.
//


#include "hubble.h"
#include "uiDraw.h"


void Hubble::draw(ogstream& gout)
{
   gout.drawHubble(pos, angle.getDegrees());
}
