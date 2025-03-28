//
//  partDragonLeft.cpp
//  OrbitSimulatorW9
//
//  Created by savanna on 3/27/25.
//


#include "partDragonLeft.h"
#include "satellite.h"
#include "uiDraw.h"
#include "fragment.h"
#include <vector>

void PartDragonLeft::destroy(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));

}

void PartDragonLeft::draw(ogstream& gout)
{
   gout.drawCrewDragonLeft(pos, angle.getRadians());
}
