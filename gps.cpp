//
//  GPS.cpp
//  CSE231_Orbit09
//
//  Created by Sara Fisk on 3/6/25.
//


#include "gps.h"
#include "partGPSCenter.h"
#include "partGPSRight.h"
#include "partGPSLeft.h"
#include "uiDraw.h"
#include "fragment.h"
#include <vector>



void GPS::draw(ogstream& gout)
{
   gout.drawGPS(pos, angle.getDegrees());
}

void GPS::destroy(std::vector <Satellite*>& satellites)
{
   satellites.push_back(new PartGPSCenter());
   satellites.push_back(new PartGPSLeft());
   satellites.push_back(new PartGPSRight());
   satellites.push_back(new Fragment);
   satellites.push_back(new Fragment);
   
}
