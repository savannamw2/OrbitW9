//
//  partHubbleLeft.cpp
//  Obrit
//
//  Created by Isabel Kamphaus on 3/27/25.
//

#include "fragment.h"
#include "partHubbleLeft.h"
#include "satellite.h"
#include "uiDraw.h"
#include <vector>

void PartHubbleLeft::destroy(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));

}

void PartHubbleLeft::draw(ogstream& gout)
{
    gout.drawHubbleLeft(pos, angle.getRadians());
}
