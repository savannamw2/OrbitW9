//
//  Sputnik.cpp
//  Orbit
//
//  Created by Isabel Kamphaus on 3/13/25.
//

#include "GPS.h"
#include "uiDraw.h"



void GPS::draw(ogstream& gout) const
{
    gout.drawSputnik(pos, angularVelocity);
}
