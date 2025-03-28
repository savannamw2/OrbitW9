//
//  partGPSCenter.cpp
//  OrbitSimulatorW9
//
//  Created by savanna on 3/27/25.
//

#include "partGPSCenter.h"
#include "satellite.h"
#include "uiDraw.h"
#include "fragment.h"
#include <vector>

void PartGPSCenter::destroy(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
}

void PartGPSCenter::draw(ogstream& gout)
{
   gout.drawGPSCenter(pos, angle.getRadians());
}
