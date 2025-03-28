//
//  partStarlinkBody.cpp
//  Obrit
//
//  Created by Isabel Kamphaus on 3/27/25.
//

//
//  partStarlinkBody.h
//  Obrit
//
//  Created by Isabel Kamphaus on 3/27/25.
//

#include "fragment.h"
#include "partStarlinkBody.h"
#include "satellite.h"
#include "uiDraw.h"
#include <vector>

void PartStarlinkBody::destroy(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
}

void PartStarlinkBody::draw(ogstream& gout)
{
    gout.drawStarlinkBody(pos, angle.getRadians());
}
