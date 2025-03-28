//
//  Sputnik.cpp
//  Orbit
//
//  Created by Isabel Kamphaus on 3/13/25.
//

#include "Sputnik.h"
#include "uiDraw.h"
#include "fragment.h"


void Sputnik::draw(ogstream& gout) const
{
    gout.drawSputnik(pos, angularVelocity);
}

void Sputnik::destroy(std::vector<Satellite*>& satellites)
{
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
   satellites.push_back(new Fragment(pos, velocity));
    satellites.push_back(new Fragment(pos, velocity));
}
