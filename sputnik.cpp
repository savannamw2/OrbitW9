//
//  Sputnik.cpp
//  Orbit
//
//  Created by Isabel Kamphaus on 3/13/25.
//

#include "sputnik.h"
#include "uiDraw.h"



void Sputnik::draw(ogstream& gout)
{
    gout.drawSputnik(pos, angularVelocity);
}
