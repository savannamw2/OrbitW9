//
//  partGPSRight.cpp
//  OrbitSimulatorW9
//
//  Created by savanna on 3/27/25.
//

#include "partGPSRight.h"
#include "satellite.h"
#include "uiDraw.h"
#include "fragment.h"
#include <vector>

void PartGPSRight::destroy(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
}

void PartGPSRight::draw(ogstream& gout)
{
   gout.drawGPSRight(pos, angle.getRadians());
}
