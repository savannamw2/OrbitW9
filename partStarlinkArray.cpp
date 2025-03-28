//
//  partStarlinkArray.cpp
//  Obrit
//
//  Created by Isabel Kamphaus on 3/27/25.
//

#include "fragment.h"
#include "partStarlinkArray.h"
#include "satellite.h"
#include "uiDraw.h"
#include <vector>

void PartStarlinkArray::destroy(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
}

void PartStarlinkArray::draw(ogstream& gout)
{
    gout.drawStarlinkArray(pos, angle.getRadians());
}
