//
//  GPS.cpp
//  CSE231_Orbit09
//
//  Created by Savanna Fisk on 3/6/25.
//


#include "hubble.h"
#include "uiDraw.h"
#include "partHubbleLeft.h"
#include "partHubbleRight.h"
#include "partHubbleComputer.h"
#include "partHubbleTelescope.h"
#include <vector>


void Hubble::draw(ogstream& gout)
{
   gout.drawHubble(pos, angle.getDegrees());
}

void Hubble::destroy(std::vector <Satellite*>& satellites)
{
   satellites.push_back(new PartHubbleComputer());
   satellites.push_back(new PartHubbleLeft());
   satellites.push_back(new PartHubbleRight());
   satellites.push_back(new PartHubbleTelescope());
   
}

