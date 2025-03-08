//
//  GPS.cpp
//  CSE231_Orbit09
//
//  Created by Sara Fisk on 3/6/25.
//


#include "gps.h"
#include "uiDraw.h"


void GPS::draw(ogstream& gout)
{
   gout.drawGPS(pos, angle.getDegrees());
}
