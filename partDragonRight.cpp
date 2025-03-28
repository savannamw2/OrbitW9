//
//  partDragonRight.cpp
//  OrbitSimulatorW9
//
//  Created by savanna on 3/27/25.
//

#include "partDragonRight.h"
#include "satellite.h"
#include "uiDraw.h"
#include "fragment.h"
#include <vector>

void PartDragonRight::destroy(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));

}

void PartDragonRight::draw(ogstream& gout)
{
   gout.drawCrewDragonRight(pos, angle.getRadians());
}
