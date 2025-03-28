//
//  partGPSLeft.cpp
//  OrbitSimulatorW9
//
//  Created by savanna on 3/27/25.
//

#include "partGPSLeft.h"
#include "satellite.h"
#include "uiDraw.h"
#include "fragment.h"
#include <vector>

void PartGPSLeft::destroy(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
}

void PartGPSLeft::draw(ogstream& gout)
{
   gout.drawGPSLeft(pos, angle.getRadians());
}
