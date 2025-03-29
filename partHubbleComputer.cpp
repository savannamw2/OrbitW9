//
//  partHubbleComputer.cpp
//  Obrit
//
//  Created by Isabel Kamphaus on 3/27/25.
//

#include "fragment.h"
#include "partHubbleComputer.h"
#include "satellite.h"
#include "uiDraw.h"
#include <vector>

void PartHubbleComputer::destroy(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));

}

void PartHubbleComputer::draw(ogstream& gout)
{
    gout.drawHubbleComputer(pos, angle.getRadians());
}

