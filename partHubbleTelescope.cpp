//
//  partHubbleTelescope.cpp
//  Obrit
//
//  Created by Isabel Kamphaus on 3/27/25.
//

#include "fragment.h"
#include "partHubbleTelescope.h"
#include "satellite.h"
#include "uiDraw.h"
#include <vector>

void PartHubbleTelescope::destroy(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
}

void PartHubbleTelescope::draw(ogstream& gout)
{
    gout.drawHubbleTelescope(pos, angle.getRadians());
}
