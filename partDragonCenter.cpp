//
//  partDragonCenter.cpp
//  OrbitSimulatorW9
//
//  Created by savanna on 3/27/25.
//

#include "partDragonCenter.h"
#include "satellite.h"
#include "uiDraw.h"
#include "fragment.h"
#include <vector>

void PartDragonCenter::destroy(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));

}

void PartDragonCenter::draw(ogstream& gout)
{
   gout.drawCrewDragonCenter(pos, angle.getRadians());
}
