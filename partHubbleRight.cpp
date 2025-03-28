//
//  partHubbleTelescope.cpp
//  Obrit
//
//  Created by Isabel Kamphaus on 3/27/25.
//

#include "fragment.h"
#include "partHubbleRight.h"
#include "satellite.h"
#include "uiDraw.h"
#include <vector>

void PartHubbleRight::destroy(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));

}

void PartHubbleRight::draw(ogstream& gout)
{
    gout.drawHubbleRight(pos, angle.getRadians());
}
